//Monster.h
#pragma once
#include <string>
#include <vector>

using namespace std;

class Monster
{
public:
    Monster();
    Monster(string monstername); // ���� �̸�

    // virtual void attack() = 0; // ���Ͱ� �����ϱ� �̱���
    void printMonsterStatus(); // ���� ����
    virtual vector<string> Droptable(string) const; // ��� ���̺�

    // void takeDamage(int damage);
    
    // getter �Լ�
    string getMonsterName(); // ���� �̸�
    int getMonsterLevel();  // ���� ����
    int getMonsterMaxHp(); // ���� �ִ� ü��
    int getMonsterHp(); // ���� ���� ü��
    int getMonsterPower(); // ���� ���ݷ�
    int getMonsterDefence(); // ���� ����

    // setter �Լ�
    void setMonsterName(string monstername); // ���� �̸�
    void setMonsterLevel(int monsterlevel); // ���� ����
    void setMonsterMaxHp(int monstermaxhp); // ���� �ִ� ü��
    bool setMonsterHp (int monsterhp); // ���� ü��
    void setMonsterPower (int monsterpower); // ���� ���ݷ�
    void setMonsterDefence(int monsterdefence); // ���� ����


protected:
    string monstername;
    int monsterlevel;
    int monstermaxhp;
    int monsterhp;
    int monsterpower;
    int monsterdefence;
  
};
