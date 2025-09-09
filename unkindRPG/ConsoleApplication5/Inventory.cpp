#include "Inventory.h"
#include <iostream>
using namespace std;

void Inventory::addItem(const string& name, int count) { // ������ �߰�
    for (auto& item : items) {
        if (item.first == name) {
            item.second += count;
            return;
        }
    }
    items.push_back({ name, count });
}

void Inventory::removeItem(const string& name, int count) { // ������ ����
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->first == name) {
            it->second -= count;
            if (it->second <= 0) {
                items.erase(it);
            }
            return;
        }
    }
    cout << "�ش� �������� �κ��丮�� �����ϴ�.\n";
}

void Inventory::showInventory() const {
    if (items.empty()) {
        cout << "�κ��丮�� ��� �ֽ��ϴ�.\n";
        return;
    }
    cout << "=== ���� �κ��丮 ===\n";
    for (const auto& item : items) {
        
        cout << item.first;
        if (item.second > 1)
        {
            cout << " x " << item.second << "\n";
        }
    }
}
