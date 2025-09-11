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
    void addItem(const string& name, int price, int count, const string& type); // 아이템 이름으로 아이템 추가 (아이템, 가격, 수량, 타입)을 넣어야함.
    void removeItem(const string& name, int count); // 아이템 이름으로 제거
    void showInventory(); // 인벤토리 열기
    pair<int, int> sellItem(const string& name, int count); // 아이템 이름으로 아이템 판매
    pair<int, int> sellItemIndex(int index, int count); // 아이템 번호로 아이템 판매
    void addGold(int amount);    // 골드 획득
    void reduceGold(int amount); // 골드 소실
    void showGold() const; // 소지 골드 확인
    int showGold(int dummy) const; // 소지 골드 반환만 하기
    tuple<int, int, string> getItemInfo(const string& name) const; // 아이템 이름으로 정보 조회 : (수량, 가격, 타입) 반환
    tuple<string, int, int> ItemInfoIndex(int index); // 아이템 번호로 정보 조회 : (이름, 수량) 반환

};

#endif
