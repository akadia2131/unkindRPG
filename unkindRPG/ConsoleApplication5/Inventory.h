#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

// ������ ���� ����ü
struct Item {
    string name;   // ������ �̸�
    int price;     // ���� 
    int quantity;  // ����
    string type;   // Ÿ��
};

class Inventory {
private:
    vector<Item> items;
    int playerGold = 0; // �÷��̾ ������ ���
    int getTypePriority(const string& type) const; // Ÿ�� �켱����

public:
    void addItem(const string& name, int price, int count, const string& type);
    void removeItem(const string& name, int count);
    void showInventory();
    pair<int, int> sellItem(const string& name, int count); // (�Ǹ� ����, �� ����)
    void addGold(int amount);    // ��� �߰�
    void reduceGold(int amount); // ��� ����
    void showGold() const; // ������ ǥ��
    tuple<int, int, string> getItemInfo(const string& name) const; // ������ ���� ��ȸ: (����, ����, Ÿ��) ��ȯ
};

#endif
