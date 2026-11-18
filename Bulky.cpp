#pragma once
#include <iostream>
#include "Inventory.cpp" // File chứa lớp cha InventoryManagement
using namespace std;

class BulkyItem : public InventoryManagement {
private:
    double volume;       
    string storage_zone; 

public:
    // Constructor khởi tạo
    BulkyItem(string id, double w, int q, double vol, string zone) 
        : InventoryManagement(id, w, q), volume(vol), storage_zone(zone) {}

    // Destructor
    ~BulkyItem() override {
        cout << "Xoa vung nho hang cong kenh" << endl;
    }

    void setVolume(double vol) {
        this->volume = vol;
    }

    double getVolume() const {
        return volume;
    }

    void setStorageZone(string zone) {
        this->storage_zone = zone;
    }

    string getStorageZone() const {
        return storage_zone;
    }

    // Ghi đè phương thức hiển thị thông tin
    void displayInfo() const override {
        cout << "Bulky Item ID: " << getItemId() << endl;
        cout << "Bulky Item Quantity: " << getQuantity() << endl;
        cout << "Single Bulky Item Weight: " << getWeight() << endl;
        cout << "Total Bulky Item Weight: " << getTotalweight() << endl;
        cout << "Volume per item: " << getVolume() << " m3" << endl;
        cout << "Total Volume: " << (getVolume() * getQuantity()) << " m3" << endl;
        cout << "Storage Zone: " << getStorageZone() << endl;
    }

    // Cảnh báo chuyên dụng cho hàng cồng kềnh
    void displayWarning() const override {
        cout << "-----CANH BAO: HANG KICH THUOC LON -----" << endl;
    }
};
