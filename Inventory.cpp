#pragma once
#include <iostream>

using namespace std;

class InventoryManagement {
private:
    string itemid;
    double weight;
    int quantity;

public:
    // Constructor khởi tạo trực tiếp dữ liệu
    InventoryManagement(string id, double w, int q) : itemid(id), weight(w), quantity(q) {}

    // Destructor (Sử dụng virtual destructor để đảm bảo an toàn khi kế thừa)
    virtual ~InventoryManagement() {
        cout<< "Xoa vung nho kho hang" << endl;
    }

    // Getter cho itemid
    string getItemId() const {
        return itemid;
    }

    // Setter cho itemid
    void setItemId(string id) {
        this->itemid = id;
    }

    // Getter cho weight (Thêm từ khóa const để tối ưu hàm đọc dữ liệu)
    double getWeight() const {
        return weight;
    }
    
    virtual void setWeight(double weight) {
        this->weight = weight;
    }

    // Getter cho quantity
    int getQuantity() const {
        return quantity;
    }

    virtual void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    // Tính tổng trọng lượng
    double getTotalweight() const {
        return weight * quantity;
    }
    virtual void displayInfo() const {
        cout << "ID: " << itemid << " | Weight: " << weight << "kg | Quantity: " << quantity << "\n";
    }
    virtual void additem() {
        quantity++;
    }

    virtual void removeitem() {
        if (quantity > 0) {
            quantity--;
        }
    }
    virtual void displayWarning() const {
    cout<< "-----INVENTORY WARNING-----" <<endl;
    }
};