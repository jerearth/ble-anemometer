package com.example.beaconscanneradc;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.le.BluetoothLeScanner;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanRecord;
import android.bluetooth.le.ScanResult;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.ParcelUuid;
import android.util.Log;
import android.util.SparseArray;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;


public class MainActivity extends AppCompatActivity {

    TextView tvUUID, tvDeviceName, tvMacAddress, tvRecordBytes;

    private String selectedDeviceMacAddress = null; // Uchovanie MAC adresy vybraného zariadenia

    private BluetoothAdapter bluetoothAdapter;
    private ArrayList<BluetoothDeviceData> deviceList = new ArrayList<>();
    private HashSet<BluetoothDeviceData> uniqueDevicesSet = new HashSet<>();

    @SuppressLint("MissingPermission")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        LinearLayout selectBtn = findViewById(R.id.search_button_container);
        selectBtn.setOnClickListener(view -> openSelectDeviceActivity());

        bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

        requestPermissions();

        if (bluetoothAdapter == null || !bluetoothAdapter.isEnabled()) {
            Intent enableIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableIntent, 1);
        } else {
            startScanning();
        }

        tvDeviceName = findViewById(R.id.tvDeviceName);
        tvUUID = findViewById(R.id.tvUUID);
        tvMacAddress = findViewById(R.id.tvMacAddress);
        tvRecordBytes = findViewById(R.id.tvRecordBytes);
    }

    @SuppressLint("MissingPermission")
    private void startScanning() {
        BluetoothLeScanner bluetoothLeScanner = bluetoothAdapter.getBluetoothLeScanner();

        ScanCallback scanCallback = new ScanCallback() {
            @Override
            public void onScanResult(int callbackType, ScanResult result) {
                super.onScanResult(callbackType, result);

                ScanRecord scanRecord = result.getScanRecord();
                String name = result.getDevice().getName();
                String macAddress = result.getDevice().getAddress();
                String uuid = "N/A";
                byte[] manufacturerData = null;

                if (name == null || name.isEmpty()) {
                    Log.d("BLE", "Skipped unnamed device: " + macAddress);
                    return;
                }

                if (scanRecord != null) {
                    // Získajte UUID
                    List<ParcelUuid> serviceUuids = scanRecord.getServiceUuids();
                    if (serviceUuids != null && !serviceUuids.isEmpty()) {
                        uuid = serviceUuids.get(0).getUuid().toString();
                    }

                    SparseArray<byte[]> manufacturerDataMap = scanRecord.getManufacturerSpecificData();
                    if (manufacturerDataMap != null && manufacturerDataMap.size() > 0) {
                        manufacturerData = manufacturerDataMap.valueAt(0);
                    }
                }

                BluetoothDeviceData device = new BluetoothDeviceData(name, uuid, macAddress, manufacturerData);

                // Aktualizujte údaje v textovom poli len pre vybrané zariadenie
                if (macAddress.equals(selectedDeviceMacAddress)) {
                    if (manufacturerData != null) {
                        String manufacturerDataHex = bytesToHex(manufacturerData);
                        tvRecordBytes.setText(manufacturerDataHex);
                        Log.d("BLE", "Updated Manufacturer Data for Selected Device: " + manufacturerDataHex);
                    } else {
                        tvRecordBytes.setText("No Manufacturer Data");
                        Log.d("BLE", "No Manufacturer Data for Selected Device: " + macAddress);
                    }
                }

                // Aktualizácia alebo pridanie zariadenia
                boolean isUpdated = false;
                for (int i = 0; i < deviceList.size(); i++) {
                    if (deviceList.get(i).getMacAddress().equals(macAddress)) {
                        deviceList.set(i, device);
                        isUpdated = true;
                        Log.d("BLE", "Updated Device: " + name + ", " + macAddress);
                        break;
                    }
                }

                if (!isUpdated) {
                    deviceList.add(device);
                    uniqueDevicesSet.add(device);
                    Log.d("BLE", "New Device: " + name + ", " + macAddress);
                }

            }

            @Override
            public void onScanFailed(int errorCode) {
                super.onScanFailed(errorCode);
                Log.e("BLE", "Scan failed with error code: " + errorCode);
            }
        };

        bluetoothLeScanner.startScan(scanCallback);
    }

    private void requestPermissions() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
            requestPermissions(new String[]{
                    android.Manifest.permission.BLUETOOTH_SCAN,
                    android.Manifest.permission.BLUETOOTH_CONNECT,
                    android.Manifest.permission.ACCESS_FINE_LOCATION
            }, 1);
        } else {
            requestPermissions(new String[]{
                    android.Manifest.permission.ACCESS_FINE_LOCATION
            }, 1);
        }
    }

    private void openSelectDeviceActivity() {
        Intent intent = new Intent(MainActivity.this, SelectDeviceActivity.class);
        intent.putParcelableArrayListExtra("deviceList", deviceList);
        startActivityForResult(intent, 100); // 100 je request kód
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 100 && resultCode == RESULT_OK) {
            int selectedPosition = data.getIntExtra("selectedPosition", -1);
            if (selectedPosition != -1 && selectedPosition < deviceList.size()) {
                BluetoothDeviceData selectedDevice = deviceList.get(selectedPosition);

                // Nastavte vybranú MAC adresu
                selectedDeviceMacAddress = selectedDevice.getMacAddress();

                // Log manufacturer data
                byte[] manufacturerData = selectedDevice.getManufacturerData();
                if (manufacturerData != null) {
                    Log.d("BBBB", "Manufacturer Data: " + bytesToHex(manufacturerData));
                } else {
                    Log.d("BBBB", "Manufacturer Data: None");
                }

                // Aktualizujte textové polia
                Log.d("BLEE", "Device Data: positionInList:" + selectedPosition + ", Name: " + selectedDevice.getName() + ", UUID: " + selectedDevice.getUuid() + ", Mac: " + selectedDevice.getMacAddress());
                tvDeviceName.setText(selectedDevice.getName() != null ? selectedDevice.getName() : "Neznáme zariadenie");
                tvUUID.setText(selectedDevice.getUuid() != null ? selectedDevice.getUuid() : "N/A");
                tvMacAddress.setText(selectedDevice.getMacAddress());
                tvRecordBytes.setText(bytesToHex(selectedDevice.getManufacturerData()));
            }
        }
    }

    private String bytesToHex(byte[] bytes) {
        if (bytes == null) return "null";
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02X ", b));
        }
        return sb.toString().trim();
    }

}