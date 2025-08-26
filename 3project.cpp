#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string name_;
    int price_;
public:
    Item(string name = "�̸�����", int price = 0)
        : name_(name), price_(price) {
    }

    void PrintInfo() const {
        cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
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
            cout << "�κ��丮�� �� á���ϴ�!" << endl;
        }
    }

    void RemoveLastItem() {
        if (size_ > 0) {
            size_--;
        }
        else {
            cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
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
            cout << "(�������)" << endl;
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
    myInventory.AddItem(Item("��", 100));
    myInventory.AddItem(Item("����", 150));
    myInventory.AddItem(Item("����", 50));
    myInventory.AddItem(Item("����", 200)); 

    cout << "===== ���� �κ��丮 =====" << endl;
    myInventory.PrintAllItems();

    myInventory.RemoveLastItem(); 
    cout << "===== ������ ������ ���� �� =====" << endl;
    myInventory.PrintAllItems();

    return 0;
}