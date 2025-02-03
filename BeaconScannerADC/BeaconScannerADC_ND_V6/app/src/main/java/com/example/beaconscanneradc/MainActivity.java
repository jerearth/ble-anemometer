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
import android.os.Handler;
import android.util.Log;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;
import java.util.HashSet;

public class MainActivity extends AppCompatActivity {

    TextView tvTemp, tvDeviceName, tvMacAddress, tvDirection, tvBatt, tvSpeed;
    ImageView ivDirection;
    private String selectedDeviceMacAddress = null;

    private BluetoothAdapter bluetoothAdapter;
    private static ArrayList<BluetoothDeviceData> deviceList = new ArrayList<>();
    private HashSet<BluetoothDeviceData> uniqueDevicesSet = new HashSet<>();

    private static final long DEVICE_TIMEOUT = 10000;
    private Handler handler = new Handler();



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

        // Initialize Bluetooth adapter
        bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        requestPermissions();

        if (bluetoothAdapter == null || !bluetoothAdapter.isEnabled()) {
            Intent enableIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableIntent, 1);
        } else {
            startScanning();
        }

        // Assign UI elements to variables
        tvDeviceName = findViewById(R.id.tvDeviceName);
        tvTemp = findViewById(R.id.tvTemp);
        tvMacAddress = findViewById(R.id.tvMacAddress);
        tvDirection = findViewById(R.id.tvDirection);
        tvSpeed = findViewById(R.id.tvSpeed);
        tvBatt = findViewById(R.id.tvBatt);
        ivDirection = findViewById(R.id.ivDirection);

        startDeviceCleanup();
    }

    // Method to start Bluetooth scanning and handle scan results
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
                byte[] scanRecordBytes_ = scanRecord != null ? scanRecord.getBytes() : null;

                // Skip devices that do not match the specified MAC address prefix
                if (!macAddress.startsWith("02:80:E1")) {
                    Log.d("BLE", "Skipped unnamed device: " + macAddress);
                    return;
                }
                int[] scanRecordBytes = toUnsignedByteArray(scanRecordBytes_);

                int n = scanRecordBytes[28] | (scanRecordBytes[29] << 8);
                Log.d("Scannn:", + scanRecordBytes.length + " " + bytesToHex(scanRecordBytes) + ", " + n);


                BluetoothDeviceData device = new BluetoothDeviceData(name, macAddress, null, 0, 0, 0, 0);
                if (scanRecordBytes != null) {
                    device.parseAnemometerValues(scanRecordBytes);
                }
                device.setLastSeenTimestamp(System.currentTimeMillis());

                if (selectedDeviceMacAddress != null && macAddress.equals(selectedDeviceMacAddress)) {
                    tvBatt.setText(String.format("%.2f", device.getBattery() / 1000.0).replace('.', ',') + "V");
                    tvTemp.setText(String.format("%.1f", device.getTemp() / 100.0).replace('.', ',') + "°C");
                    tvSpeed.setText(String.valueOf((float) device.getSpeed()/100).replace('.', ','));
                    tvDirection.setText(device.getDirection() + "°");

                    rotateImageSmoothly(ivDirection, device.getDirection());
                    Log.d("aaaa", device.getDirection() + "");

                    tvDeviceName.setText(name != null ? name : "Neznáme zariadenie");
                    tvMacAddress.setText(macAddress);
                }

                // Updating data in the text field only for the selected device
                if (macAddress.equals(selectedDeviceMacAddress) && selectedDeviceMacAddress != null) {
                    tvDeviceName.setText(name != null ? name : "Neznáme zariadenie");
                    tvMacAddress.setText(macAddress);
                }

                // Updating or adding a device
                boolean isUpdated = false;
                for (int i = 0; i < deviceList.size(); i++) {
                    if (deviceList.get(i).getMacAddress().equals(macAddress)) {
                        deviceList.set(i, device);
                        isUpdated = true;
                        Log.d("BLE", "Updated Device: " + name + ", " + macAddress);
                        Log.d("dddd", device.getDirection() + "" + device.getName());
                        break;
                    }
                }

                if (!isUpdated) {
                    synchronized (deviceList) {
                        deviceList.add(device);
                    }
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

    // Request necessary permissions for Bluetooth scanning
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

    // Open device selection activity
    private void openSelectDeviceActivity() {
        Intent intent = new Intent(MainActivity.this, SelectDeviceActivity.class);
        intent.putParcelableArrayListExtra("deviceList", deviceList);
        startActivityForResult(intent, 100); // 100 je request kód
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 100 && resultCode == RESULT_OK) {
            selectedDeviceMacAddress = data.getStringExtra("selectedMacAddress");

        }
    }

    private String bytesToHex(int[] bytes) {
        if (bytes == null) return "null";
        StringBuilder sb = new StringBuilder();
        for (int b : bytes) {
            sb.append(String.format("%02X ", (byte) (b & 0xFF)));
        }
        return sb.toString().trim();
    }

    private void rotateImageSmoothly(ImageView ivDirection, int targetDegrees) {
        // Animation preloading
        float currentRotation = ivDirection.getRotation() % 360;
        if (currentRotation < 0) currentRotation += 360;

        float delta = targetDegrees - currentRotation;

        if (delta > 180) {
            delta -= 360;
        } else if (delta < -180) {
            delta += 360;
        }

        ivDirection.setRotation(targetDegrees);
    }


    public static synchronized ArrayList<BluetoothDeviceData> getDeviceList() {
        return new ArrayList<>(deviceList);
    }

    // Remove inactive devices from the list
    private void removeInactiveDevices() {
        long currentTime = System.currentTimeMillis();
        synchronized (deviceList) {
            for (int i = deviceList.size() - 1; i >= 0; i--) {
                BluetoothDeviceData device = deviceList.get(i);
                if (currentTime - device.getLastSeenTimestamp() > DEVICE_TIMEOUT) {
                    Log.d("DEBUG", "Removing inactive device: " + device.getMacAddress());
                    deviceList.remove(i);
                }
            }
        }
    }

    // Periodically clean up the device list
    private void startDeviceCleanup() {
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                removeInactiveDevices();
                handler.postDelayed(this, 500);
            }
        }, DEVICE_TIMEOUT);
    }

    public static int[] toUnsignedByteArray(byte[] signedBytes) {
        int[] unsignedBytes = new int[signedBytes.length];
        for (int i = 0; i < signedBytes.length; i++) {
            unsignedBytes[i] = signedBytes[i] & 0xFF; // Convert to unsigned
        }
        return unsignedBytes;
    }





}