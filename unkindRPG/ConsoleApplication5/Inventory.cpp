#include "Inventory.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

// 인벤토리 내 아이템 타입 정렬
int Inventory::getTypePriority(const string& type) const
{
    static map<string, int> priority = {
        {"무기", 1}, {"갑옷", 2}, {"소모", 3}, {"기타", 4}
    };
    auto it = priority.find(type);
    return (it != priority.end()) ? it->second : 999; // 정의 안된건 맨 뒤
}

// 아이템 추가
void Inventory::addItem(const string& name, int price, int count, const string& type)
{
    for (auto& item : items) {
        if (item.name == name && item.type == type) { // 같은 아이템이면 수량만 추가
            item.quantity += count;
            return;
        }
    }
    items.push_back({ name, price, count, type });
}

// 아이템 제거
void Inventory::removeItem(const string& name, int count)
{
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

// 아이템 이름을 입력받아서 판매하기. (아이템이름, 수량)
pair<int, int> Inventory::sellItem(const string& name, int count)
{
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name) {
            int sellCount = min(count, it->quantity); // 실제 판매된 수량
            int totalPrice = it->price * sellCount;   // 총 판매 가격

            it->quantity -= sellCount;
            if (it->quantity <= 0) {
                items.erase(it);
            }

            playerGold += totalPrice; // 내 소지금에 누적

            return { sellCount, totalPrice }; // 반환값은 (판매 수량, 총 가격)
        }
    }
    cout << "해당 아이템이 인벤토리에 없습니다.\n";
    return { 0, 0 }; // 실패 시 (0, 0)
}

// 아이템 번호를 입력받아 아이템을 판매하기.
pair<int, int> Inventory::sellItemIndex(int index, int count)
{
    if (index < 1 || index >(int)items.size())
    {
        cout << "[ 잘못된 번호입니다 ] \n";
        return { 0,0 };
    }
    auto it = items.begin() + (index - 1);
    int sellCount = min(count, it->quantity); // 실제 판매된 수량
    int totalPrice = it->price * sellCount;   // 총 판매 가격
    it->quantity -= sellCount;
    if (it->quantity <= 0)
    {
        items.erase(it);
    }
    playerGold += totalPrice; // 내 소지금에 누적
    return { sellCount, totalPrice }; // 반환값은 (판매 수량, 총 가격)        
}

// 인벤토리 출력 
void Inventory::showInventory()
{
    if (items.empty()) {
        cout << "인벤토리가 비어 있습니다.\n";
        return;
    }
    
    cout << "=========[ 인벤토리 ]=========" << endl;

    sort(items.begin(), items.end(), [&](const Item& a, const Item& b) {
        int pa = getTypePriority(a.type);
        int pb = getTypePriority(b.type);
        if (pa == pb) {
            return a.name < b.name;
        }
        return pa < pb;
        }); // 혹시 모를 에러 방지를 위해 다른타입이면서 같은이름의 아이템을 별도로 표기함.

    int index = 1;
    for (const auto& item : items) {
        cout << "[" << index++ << "][" << item.type << "] " << item.name;
        if (item.quantity > 1) {
            cout << " x " << item.quantity;
        }
        cout << "\n";
    }
}

// 아이템의 이름을 입력받아 아이템의 정보만 출력
tuple<int, int, string> Inventory::getItemInfo(const string& name) const  // 아이템 정보만 출력
{
    for (const auto& item : items) {
        if (item.name == name) {
            return { item.quantity, item.price, item.type };
        }
    }
    return { 0, 0, "" }; // 아이템 없으면 (0,0,"")
}

// 인벤토리 내의 아이템 번호를 입력하여 아이템의 이름과 현재 보유 수량을 출력
tuple<string, int, int> Inventory::ItemInfoIndex(int index)
{
    if (index < 1 || index >(int)items.size()) {
        cout << "[ 잘못된 번호입니다 ] \n";
        return { "", 0, 0 };
    }
    auto it = items.begin() + (index - 1);
    string itemName = it->name; // 아이템 이름
    int currentQuantity = it->quantity; // 현재 수량
    int price = it->price; // 가격

    return { itemName, currentQuantity, price };
}

void Inventory::showGold() const
{
    cout << "[ 현재 소지금 : " << playerGold << "G ]" << endl;
}

void Inventory::addGold(int amount) // 골드 획득하기
{
    if (amount > 0) {
        playerGold += amount;
        cout << amount << " G 획득!\n";
    }
    else {
        // error 메세지
        cout << "추가할 골드는 0보다 커야 합니다.\n";
    }
}

void Inventory::reduceGold(int amount) // 골드 소실
{
    if (amount <= 0) {
        cout << "차감할 골드는 0보다 커야 합니다.\n";
        return;
    }
    if (playerGold >= amount) {
        playerGold -= amount;
        cout << amount << " G 사용!\n";
    }
    else {
        // error메세지
        cout << "골드가 부족합니다! (현재 보유: " << playerGold << " G)\n";
    }
}