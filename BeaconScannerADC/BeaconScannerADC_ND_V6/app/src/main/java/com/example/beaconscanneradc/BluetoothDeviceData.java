package com.example.beaconscanneradc;

import android.os.Parcel;
import android.os.Parcelable;
import android.util.Log;

import androidx.annotation.NonNull;

public class BluetoothDeviceData implements Parcelable {
    private String name;
    private String macAddress;
    private int[] scanRecordData;
    private long lastSeenTimestamp;
    private int speed;
    private int direction;
    private int temp;
    private long battery;

    // Constructor to initialize Bluetooth device data
    public BluetoothDeviceData(String name, String macAddress, int[] scanRecordData, int speed, int direction, long battery, int temp) {
        this.name = name;
        this.macAddress = macAddress;
        this.scanRecordData = scanRecordData;
        this.speed = speed;
        this.direction = direction;
        this.battery = battery;
        this.temp = temp;
    }

    // Constructor to recreate object from a Parcel
    protected BluetoothDeviceData(Parcel in) {
        name = in.readString();
        macAddress = in.readString();
        scanRecordData = in.createIntArray();
        speed = in.readInt();
        direction = in.readInt();
        battery = in.readInt();
        temp = in.readInt();
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

    @NonNull
    @Override
    public String toString() {
        return getSpeed() + ", " + getDirection() + ", " + getTemp() + ", " + getBattery();
    }

    // Getters for device attributes
    public String getName() {
        return name;
    }

    public String getMacAddress() {
        return macAddress;
    }

    public int getSpeed() {
        return speed;
    }

    public int getDirection() {
        return direction;
    }

    public long getBattery() {
        return battery;
    }

    public int getTemp() {
        return temp;
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel parcel, int flags) {
        parcel.writeString(name);
        parcel.writeString(macAddress);
        parcel.writeIntArray(scanRecordData);
        parcel.writeInt(speed);
        parcel.writeInt(direction);
        parcel.writeLong(battery);
        parcel.writeInt(temp);
    }

    public long getLastSeenTimestamp() {
        return lastSeenTimestamp;
    }

    public void setLastSeenTimestamp(long lastSeenTimestamp) {
        this.lastSeenTimestamp = lastSeenTimestamp;
    }

    // Method to extract anemometer values from scan record bytes
    public void parseAnemometerValues(int[] scanRecordBytes) {
        if (scanRecordBytes != null) {
            this.temp = (scanRecordBytes[24] | (scanRecordBytes[25] << 8));
            this.battery = (scanRecordBytes[22] | (scanRecordBytes[23] << 8));
            this.speed = (scanRecordBytes[28] | (scanRecordBytes[29] << 8));
            this.direction = (scanRecordBytes[26] | (scanRecordBytes[27] << 8));
            System.out.println(this);
        } else {
            Log.e("BLE error", "chyba parseAnemometerValues");
        }
    }
}
