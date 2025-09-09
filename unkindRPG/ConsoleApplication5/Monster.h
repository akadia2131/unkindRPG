//Monster.h
#pragma once
#include <string>
#include <vector>

using namespace std;

class Monster
{
public:
    Monster();
    Monster(string name); // ���� �̸�

    // virtual void attack() = 0; // ���Ͱ� �����ϱ� �̱���
    void printMonsterStatus(); // ���� ����
    virtual vector<string> Droptable(int count = 0) const; // ��� ���̺�

    // void takeDamage(int damage);
    
    // getter �Լ�
    string getName(); // ���� �̸�
    int getLevel();  // ���� ����
    int getHP(); // ���� ü��
    int getPower(); // ���� ���ݷ�
    int getDefence(); // ���� ����

    // setter �Լ�
    void setName(string name); // ���� �̸�
    void setLevel(int level); // ���� ����
    bool setHP (int hp); // ���� ü��
    void setPower (int power); // ���� ���ݷ�
    void setDefence(int defence); // ���� ����


protected:
    string name;  
    int level;
    int hp;
    int power;
    int defence;
  
};
