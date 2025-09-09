#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
using namespace std;

class Inventory {
private:
    vector<pair<string, int>> items; // 아이템 이름, 수량

public:
    void addItem(const string& name, int count = 1);
    void removeItem(const string& name, int count = 1);
    void showInventory() const;
};

#endif