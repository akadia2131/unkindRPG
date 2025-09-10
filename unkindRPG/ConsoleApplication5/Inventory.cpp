#include "Inventory.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

// �κ��丮 �� ������ Ÿ�� ����
int Inventory::getTypePriority(const string& type) const {
    static map<string, int> priority = {
        {"����", 1}, {"����", 2}, {"�Ҹ�", 3}, {"��Ÿ", 4}
    };
    auto it = priority.find(type);
    return (it != priority.end()) ? it->second : 999; // ���� �ȵȰ� �� ��
}

// ������ �߰�
void Inventory::addItem(const string& name, int price, int count, const string& type) {
    for (auto& item : items) {
        if (item.name == name && item.type == type) { // ���� �������̸� ������ �߰�
            item.quantity += count;
            return;
        }
    }
    items.push_back({ name, price, count, type });
}

// ������ ����
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
    cout << "�ش� �������� �κ��丮�� �����ϴ�.\n";
}

// ������ �Ǹ�
pair<int, int> Inventory::sellItem(const string& name, int count) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name) {
            int sellCount = min(count, it->quantity); // ���� �Ǹŵ� ����
            int totalPrice = it->price * sellCount;   // �� �Ǹ� ����

            it->quantity -= sellCount;
            if (it->quantity <= 0) {
                items.erase(it);
            }

            playerGold += totalPrice; // �� �����ݿ� ����

            return { sellCount, totalPrice }; // (�Ǹ� ����, �� ����)
        }
    }

    cout << "�ش� �������� �κ��丮�� �����ϴ�.\n";
    return { 0, 0 }; // ���� �� (0, 0)
}

// �κ��丮 ��� 
void Inventory::showInventory() {
    if (items.empty()) {
        cout << "�κ��丮�� ��� �ֽ��ϴ�.\n";
        return;
    }

    sort(items.begin(), items.end(), [&](const Item& a, const Item& b) {
        int pa = getTypePriority(a.type);
        int pb = getTypePriority(b.type);
        if (pa == pb) {
            return a.name < b.name; // ���� Ÿ���̸� �̸���
        }
        return pa < pb;
        });

    cout << "=== [ �κ��丮 ] ===\n";
    for (const auto& item : items) {
        cout << "[" << item.type << "] " << item.name;
        if (item.quantity > 1) {
            cout << " x " << item.quantity;
        }
        cout << "\n";
    }
}

tuple<int, int, string> Inventory::getItemInfo(const string& name) const { // ������ ������ ���
    for (const auto& item : items) {
        if (item.name == name) {
            return { item.quantity, item.price, item.type };
        }
    }
    return { 0, 0, "" }; // ������ ������ (0,0,"")
}

void Inventory::showGold() const {
    cout << "[���� ������ : " << playerGold << "G]" << endl;
}

void Inventory::addGold(int amount) { // ��� ȹ���ϱ�
    if (amount > 0) {
        playerGold += amount;
        cout << amount << " G ȹ��!\n";
    }
    else {
        cout << "�߰��� ���� 0���� Ŀ�� �մϴ�.\n";
    }
}

void Inventory::reduceGold(int amount) { // ��� �ҽ�
    if (amount <= 0) {
        cout << "������ ���� 0���� Ŀ�� �մϴ�.\n";
        return;
    }
    if (playerGold >= amount) {
        playerGold -= amount;
        cout << amount << " G ���!\n";
    }
    else {
        cout << "��尡 �����մϴ�! (���� ����: " << playerGold << " G)\n";
    }
}