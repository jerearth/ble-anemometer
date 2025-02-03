package com.example.beaconscanneradc;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout;

import java.util.ArrayList;

public class SelectDeviceActivity extends AppCompatActivity {

    private DeviceListAdapter adapter;
    private ArrayList<BluetoothDeviceData> deviceList;
    private SwipeRefreshLayout swipeRefreshLayout;
    private Handler handler = new Handler(); // Na plánovanie obnovy
    private final int REFRESH_INTERVAL = 1000; // Interval v milisekundách (1 sekunda)

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_select_device);

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        ListView listViewDevices = findViewById(R.id.listViewDevices);
        swipeRefreshLayout = findViewById(R.id.swipeRefreshLayout);
        deviceList = MainActivity.getDeviceList(); // Získať zoznam zo statickej metódy
        Log.d("DEBUG", "Received device list in SelectDeviceActivity: Size = " + deviceList.size());

        adapter = new DeviceListAdapter(this, deviceList);
        listViewDevices.setAdapter(adapter);

        // Nastavenie listenera pre aktualizáciu cez SwipeRefresh
        swipeRefreshLayout.setOnRefreshListener(() -> {
            refreshDeviceList();
            swipeRefreshLayout.setRefreshing(false); // Zastaviť vizuálnu indikáciu
        });

        // Nastavenie listenera pre tlačidlo Hľadať
        LinearLayout researchBtn = findViewById(R.id.research_button_container);
        researchBtn.setOnClickListener(v -> refreshDeviceList());

        // Listener na výber zariadenia
        listViewDevices.setOnItemClickListener((parent, view, position, id) -> {
            // Nastavenie výsledku a ukončenie aktivity
            Intent resultIntent = new Intent();
            resultIntent.putExtra("selectedMacAddress", deviceList.get(position).getMacAddress());
            setResult(RESULT_OK, resultIntent);
            finish();
        });

        // Nastavenie tlačidla Späť
        LinearLayout backBtn = findViewById(R.id.back_button_container);
        backBtn.setOnClickListener(view -> finish());

        // Spustenie pravidelného obnovovania
        startPeriodicUpdate();
    }

    private void refreshDeviceList() {
        ArrayList<BluetoothDeviceData> updatedList = MainActivity.getDeviceList();
        Log.d("DEBUG", "Refreshing device list: New size = " + updatedList.size());
        deviceList.clear();
        deviceList.addAll(updatedList);
        adapter.notifyDataSetChanged();
    }

    private void startPeriodicUpdate() {
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                Log.d("DEBUG", "Periodic update triggered");
                refreshDeviceList(); // Zabezpečíme, že sa aktualizuje deviceList a adapter
                handler.postDelayed(this, REFRESH_INTERVAL); // Opakuj každú sekundu
            }
        }, REFRESH_INTERVAL);
    }


    @Override
    protected void onResume() {
        super.onResume();
        refreshDeviceList();
        Log.d("DEBUG", "Activity resumed and list refreshed.");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        handler.removeCallbacksAndMessages(null); // Zastav plánované úlohy
    }
}
