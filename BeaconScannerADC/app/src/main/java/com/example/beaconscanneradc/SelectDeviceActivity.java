package com.example.beaconscanneradc;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.ListView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;

public class SelectDeviceActivity extends AppCompatActivity {

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
        ArrayList<BluetoothDeviceData> deviceList = getIntent().getParcelableArrayListExtra("deviceList");

        DeviceListAdapter adapter = new DeviceListAdapter(this, deviceList);
        listViewDevices.setAdapter(adapter);

        listViewDevices.setOnItemClickListener((parent, view, position, id) -> {
            // Nastavenie výsledku a ukončenie aktivity
            Intent resultIntent = new Intent();
            resultIntent.putExtra("selectedPosition", position);
            setResult(RESULT_OK, resultIntent);
            finish();
        });

        LinearLayout backBtn = findViewById(R.id.back_button_container);
        backBtn.setOnClickListener(view -> finish());
    }

}