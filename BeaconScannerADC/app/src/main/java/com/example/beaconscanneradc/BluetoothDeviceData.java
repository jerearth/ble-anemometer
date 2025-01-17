package com.example.beaconscanneradc;

import android.os.Parcel;
import android.os.Parcelable;

public class BluetoothDeviceData implements Parcelable {
    private String name;
    private String uuid;
    private String macAddress;
    private byte[] manufacturerData; // Pridáme pole pre manufacturer data

    public BluetoothDeviceData(String name, String uuid, String macAddress, byte[] manufacturerData) {
        this.name = name;
        this.uuid = uuid;
        this.macAddress = macAddress;
        this.manufacturerData = manufacturerData;
    }

    protected BluetoothDeviceData(Parcel in) {
        name = in.readString();
        uuid = in.readString();
        macAddress = in.readString();
        manufacturerData = in.createByteArray();
    }

    public static final Creator<BluetoothDeviceData> CREATOR = new Creator<BluetoothDeviceData>() {
        @Override
        public BluetoothDeviceData createFromParcel(Parcel in) {
            return new BluetoothDeviceData(in);
        }

        @Override
        public BluetoothDeviceData[] newArray(int size) {
            return new BluetoothDeviceData[size];
        }
    };

    public String getName() {
        return name;
    }

    public String getUuid() {
        return uuid;
    }

    public String getMacAddress() {
        return macAddress;
    }

    public byte[] getManufacturerData() {
        return manufacturerData;
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel parcel, int flags) {
        parcel.writeString(name);
        parcel.writeString(uuid);
        parcel.writeString(macAddress);
        parcel.writeByteArray(manufacturerData);
    }
}
