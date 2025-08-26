#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string name_;
    int price_;
public:
    Item(string name = "이름없음", int price = 0)
        : name_(name), price_(price) {
    }

    void PrintInfo() const {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }
};


template <typename T>
class Inventory {
private:
    T* pItems_;     
    int capacity_;   
    int size_;       

public:
  
    Inventory(int capacity = 10)
        : capacity_(capacity), size_(0)
    {
        if (capacity_ <= 0) capacity_ = 1;
        pItems_ = new T[capacity_];
    }

    ~Inventory() {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    void AddItem(const T& item) {
        if (size_ < capacity_) {
            pItems_[size_] = item;
            size_++;
        }
        else {
            cout << "인벤토리가 꽉 찼습니다!" << endl;
        }
    }

    void RemoveLastItem() {
        if (size_ > 0) {
            size_--;
        }
        else {
            cout << "인벤토리가 비어있습니다." << endl;
        }
    }

    int GetSize() const {
        return size_;
    }

    int GetCapacity() const {
        return capacity_;
    }

    void PrintAllItems() const {
        if (size_ == 0) {
            cout << "(비어있음)" << endl;
        }
        else {
            for (int i = 0; i < size_; i++) {
                pItems_[i].PrintInfo();
            }
        }
    }
};
int main() {
    Inventory<Item> myInventory(3); 
    myInventory.AddItem(Item("검", 100));
    myInventory.AddItem(Item("방패", 150));
    myInventory.AddItem(Item("포션", 50));
    myInventory.AddItem(Item("투구", 200)); 

    cout << "===== 현재 인벤토리 =====" << endl;
    myInventory.PrintAllItems();

    myInventory.RemoveLastItem(); 
    cout << "===== 마지막 아이템 제거 후 =====" << endl;
    myInventory.PrintAllItems();

    return 0;
}