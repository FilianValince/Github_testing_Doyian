#pragma once
#include <iostream>
#include "Inventory.cpp" 
using namespace std;

class fragileItem : public InventoryManagement { 
private:
    string type;

public:
    // Constructor
    fragileItem(string id, double w, int q, string t) 
        : InventoryManagement(id, w, q), type(t) {}
    // Destructor xoa bo nho
    ~fragileItem() override {
        cout << "Xoa vung nho hang de vo" << endl;
    }

    void setType(string type) {
        this->type = type;
    }

    // Thêm const cho hàm getter không thay đổi trạng thái
    string getType() const {
        return type;
    }

    // Ghi đè hàm hiển thị thông tin
    void displayInfo() const override {
        cout << "Fragile Item ID: " << getItemId() << endl;
        cout << "Fragile Item Quantity: " << getQuantity() << endl;
        cout << "Single Fragile Item Weight: " << getWeight() << endl;
        cout << "Total Fragile Item Weight: " << getTotalweight() << endl;
        cout << "Fragile Item Type: " << getType() << endl;
    }

    // Thêm const cho hàm in cảnh báo
    void displayWarning() const override {
        cout << "-----CANH BAO: HANG DE VO-----" << endl;
    }
};