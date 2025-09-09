#include "Inventory.h"
#include <iostream>
using namespace std;

void Inventory::addItem(const string& name, int count) { // 아이템 추가
    for (auto& item : items) {
        if (item.first == name) {
            item.second += count;
            return;
        }
    }
    items.push_back({ name, count });
}

void Inventory::removeItem(const string& name, int count) { // 아이템 제거
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->first == name) {
            it->second -= count;
            if (it->second <= 0) {
                items.erase(it);
            }
            return;
        }
    }
    cout << "해당 아이템이 인벤토리에 없습니다.\n";
}

void Inventory::showInventory() const {
    if (items.empty()) {
        cout << "인벤토리가 비어 있습니다.\n";
        return;
    }
    cout << "=== 현재 인벤토리 ===\n";
    for (const auto& item : items) {
        
        cout << item.first;
        if (item.second > 1)
        {
            cout << " x " << item.second << "\n";
        }
    }
}
