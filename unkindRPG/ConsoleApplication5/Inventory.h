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
    void addItem(const string& name, int price, int count, const string& type); // ������ �̸����� ������ �߰� (������, ����, ����, Ÿ��)�� �־����.
    void removeItem(const string& name, int count); // ������ �̸����� ����
    void showInventory(); // �κ��丮 ����
    pair<int, int> sellItem(const string& name, int count); // ������ �̸����� ������ �Ǹ�
    pair<int, int> sellItemIndex(int index, int count); // ������ ��ȣ�� ������ �Ǹ�
    void addGold(int amount);    // ��� ȹ��
    void reduceGold(int amount); // ��� �ҽ�
    void showGold() const; // ���� ��� Ȯ��
    int showGold(int dummy) const; // ���� ��� ��ȯ�� �ϱ�
    tuple<int, int, string> getItemInfo(const string& name) const; // ������ �̸����� ���� ��ȸ : (����, ����, Ÿ��) ��ȯ
    tuple<string, int, int> ItemInfoIndex(int index); // ������ ��ȣ�� ���� ��ȸ : (�̸�, ����) ��ȯ

};

#endif
