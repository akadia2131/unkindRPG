#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

// 아이템 정보 구조체
struct Item {
    string name;   // 아이템 이름
    int price;     // 가격 
    int quantity;  // 수량
    string type;   // 타입
};

class Inventory {
private:
    vector<Item> items;
    int playerGold = 0; // 플레이어가 보유한 골드
    int getTypePriority(const string& type) const; // 타입 우선순위

public:
    void addItem(const string& name, int price, int count, const string& type);
    void removeItem(const string& name, int count);
    void showInventory();
    pair<int, int> sellItem(const string& name, int count); // (판매 개수, 총 가격)
    void addGold(int amount);    // 골드 추가
    void reduceGold(int amount); // 골드 감소
    void showGold() const; // 소지금 표시
    tuple<int, int, string> getItemInfo(const string& name) const; // 아이템 정보 조회: (수량, 가격, 타입) 반환
};

#endif
