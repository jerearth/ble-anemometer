package com.example.beaconscanneradc;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.List;

public class DeviceListAdapter extends android.widget.ArrayAdapter<BluetoothDeviceData> {

    public DeviceListAdapter(@NonNull Context context, List<BluetoothDeviceData> devices) {
        super(context, R.layout.devices_list_item, devices);
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.devices_list_item, parent, false);
        }

        BluetoothDeviceData device = getItem(position);

        TextView listDeviceName = convertView.findViewById(R.id.listDeviceName);
        TextView listUUID = convertView.findViewById(R.id.listUUID);
        TextView listMac = convertView.findViewById(R.id.listMac);

        if (device != null) {
            listDeviceName.setText(device.getName() != null ? device.getName() : "Neznáme zariadenie");
            listUUID.setText(device.getUuid() != null ? device.getUuid() : "N/A");
            listMac.setText(device.getMacAddress());
        }

        return convertView;
    }
}
