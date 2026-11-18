#include <iostream>
#include "Inventory.cpp"     // Lớp cha
#include "Fragileitem.cpp"   // Subclass 1: Hàng dễ vỡ
#include "Chemical.cpp"      // Subclass 2: Hóa chất
#include "Bulky.cpp"         // Subclass 3: Hàng cồng kềnh

using namespace std;

int main() {
    

   
    cout << "           INVENTORY MANAGEMENT"     << endl;
    cout << "=================================================" <<endl;

    // Khởi tạo mảng con trỏ lớp cơ sở để thể hiện tính ĐA HÌNH (Polymorphism)
    const int TOTAL_ITEMS = 3;
    InventoryManagement* inventoryList[TOTAL_ITEMS];

    // Cấp phát bộ nhớ động cho các lớp con
    inventoryList[0] = new fragileItem("F001", 1.2, 5, "Thuy tinh cao cap"); 
    inventoryList[1] = new ChemicalItem("C001", 2.5, 2, "UN1789", true);     
    inventoryList[2] = new BulkyItem("B001", 15.0, 1, 1.8, "Zone-Heavy");   

    // 1. Kiểm tra tính năng hiển thị thông tin đa hình (displayInfo)
    for (int i = 0; i < TOTAL_ITEMS; ++i) {
        cout << "--- ITEM INFOMATION NUMBER " << (i + 1) << " ---"<<endl;
        inventoryList[i]->displayInfo(); // Gọi đúng hàm của lớp con nhờ virtual
        
        // Thử nghiệm phương thức tăng số lượng (additem) từ lớp cha[cite: 5]
        inventoryList[i]->additem();
        cout << "->  new quantity: " << inventoryList[i]->getQuantity() << endl;
        cout << "-> Updated weight: " << inventoryList[i]->getTotalweight() << " kg "<< endl;
        
    }
    cout << "Remove item " << inventoryList[0]->getItemId() << ":" << endl;
    inventoryList[0]->removeitem();
    cout << "->  new quantity: " << inventoryList[0]->getQuantity() << endl;
    cout << "-> Updated weight: " << inventoryList[0]->getTotalweight() << " kg "<< endl;

   
    cout << "           CLEAR MEMORY          "<< endl;
    cout << "================================================="<<endl;

    // 2. Giải phóng bộ nhớ động
    // Nhờ có virtual destructor trong InventoryManagement, destructor của lớp con 
    // và lớp cha sẽ được gọi đầy đủ theo đúng thứ tự, tránh rò rỉ bộ nhớ[cite: 2, 3, 4, 5].
    for (int i = 0; i < TOTAL_ITEMS; ++i) {
        delete inventoryList[i];
        cout << "-------------------------------------------------"<< endl;
    }
    cin.get();
    return 0;
}
