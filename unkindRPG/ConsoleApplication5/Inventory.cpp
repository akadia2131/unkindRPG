#include "Inventory.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

// 인벤토리 내 아이템 타입 정렬
int Inventory::getTypePriority(const string& type) const {
    static map<string, int> priority = {
        {"무기", 1}, {"갑옷", 2}, {"소모", 3}, {"기타", 4}
    };
    auto it = priority.find(type);
    return (it != priority.end()) ? it->second : 999; // 정의 안된건 맨 뒤
}

// 아이템 추가
void Inventory::addItem(const string& name, int price, int count, const string& type) {
    for (auto& item : items) {
        if (item.name == name && item.type == type) { // 같은 아이템이면 수량만 추가
            item.quantity += count;
            return;
        }
    }
    items.push_back({ name, price, count, type });
}

// 아이템 제거
void Inventory::removeItem(const string& name, int count) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name) {
            it->quantity -= count;
            if (it->quantity <= 0) {
                items.erase(it);
            }
            return;
        }
    }
    cout << "해당 아이템이 인벤토리에 없습니다.\n";
}

// 아이템 판매
pair<int, int> Inventory::sellItem(const string& name, int count) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name) {
            int sellCount = min(count, it->quantity); // 실제 판매된 수량
            int totalPrice = it->price * sellCount;   // 총 판매 가격

            it->quantity -= sellCount;
            if (it->quantity <= 0) {
                items.erase(it);
            }

            playerGold += totalPrice; // 내 소지금에 누적

            return { sellCount, totalPrice }; // (판매 수량, 총 가격)
        }
    }

    cout << "해당 아이템이 인벤토리에 없습니다.\n";
    return { 0, 0 }; // 실패 시 (0, 0)
}

// 인벤토리 출력 
void Inventory::showInventory() {
    if (items.empty()) {
        cout << "인벤토리가 비어 있습니다.\n";
        return;
    }

    sort(items.begin(), items.end(), [&](const Item& a, const Item& b) {
        int pa = getTypePriority(a.type);
        int pb = getTypePriority(b.type);
        if (pa == pb) {
            return a.name < b.name; // 같은 타입이면 이름순
        }
        return pa < pb;
        });

    cout << "=== [ 인벤토리 ] ===\n";
    for (const auto& item : items) {
        cout << "[" << item.type << "] " << item.name;
        if (item.quantity > 1) {
            cout << " x " << item.quantity;
        }
        cout << "\n";
    }
}

tuple<int, int, string> Inventory::getItemInfo(const string& name) const { // 아이템 정보만 출력
    for (const auto& item : items) {
        if (item.name == name) {
            return { item.quantity, item.price, item.type };
        }
    }
    return { 0, 0, "" }; // 아이템 없으면 (0,0,"")
}

void Inventory::showGold() const {
    cout << "[현재 소지금 : " << playerGold << "G]" << endl;
}

void Inventory::addGold(int amount) { // 골드 획득하기
    if (amount > 0) {
        playerGold += amount;
        cout << amount << " G 획득!\n";
    }
    else {
        cout << "추가할 골드는 0보다 커야 합니다.\n";
    }
}

void Inventory::reduceGold(int amount) { // 골드 소실
    if (amount <= 0) {
        cout << "차감할 골드는 0보다 커야 합니다.\n";
        return;
    }
    if (playerGold >= amount) {
        playerGold -= amount;
        cout << amount << " G 사용!\n";
    }
    else {
        cout << "골드가 부족합니다! (현재 보유: " << playerGold << " G)\n";
    }
}