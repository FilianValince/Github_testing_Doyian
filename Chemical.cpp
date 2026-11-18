#pragma once
#include <iostream>
#include "Inventory.cpp" // File chứa lớp cha InventoryManagement
using namespace std;

class ChemicalItem : public InventoryManagement {
private:
    string hazmatcode; 
    bool iscorrosive;  

public:
    // Constructor khởi tạo
    ChemicalItem(string id, double w, int q, string code, bool corrosive) 
        : InventoryManagement(id, w, q), hazmatcode(code), iscorrosive(corrosive) {}

    // Destructor
    ~ChemicalItem() override {
        cout << "Xoa vung nho hoa chat nguy hiem" << endl;
    }

    void setHazmatCode(string code) {
        this->hazmatcode = code;
    }

    string getHazmatCode() const {
        return hazmatcode;
    }

    void setIsCorrosive(bool corrosive) {
        this->iscorrosive = corrosive;
    }

    bool getIsCorrosive() const {
        return iscorrosive;
    }

    // Ghi đè phương thức hiển thị thông tin
    void displayInfo() const override {
        cout << "Chemical Item ID: " << getItemId() << endl;
        cout << "Chemical Item Quantity: " << getQuantity() << endl;
        cout << "Single Chemical Item Weight: " << getWeight() << endl;
        cout << "Total Chemical Item Weight: " << getTotalweight() << endl;
        cout << "Hazmat Code: " << getHazmatCode() << endl;
        cout << "Is Corrosive: " << (getIsCorrosive() ? "Yes" : "No") << endl;
    }

    // Cảnh báo chuyên dụng cho hóa chất
    void displayWarning() const override {
        cout << "-----CANH BAO: HOA CHAT DOC HAI / AN MON-----" << endl;
    }
};