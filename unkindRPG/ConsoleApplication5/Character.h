//Character.h
#pragma once
#include <string>

using namespace std;

class Character
{
public:
    Character();
    Character(string name); // ���� �̸�

    // virtual void attack() = 0; // ���Ͱ� �����ϱ� �̱���
    void printCharacterStatus(); // ���� ����


    // getter �Լ�
    string getCharacterName(); // ĳ���� �̸�
    int getCharacterLevel();  // ĳ���� ����
    int getCharacterHP(); // ĳ���� ü��
    int getCharacterPower(); // ĳ���� ���ݷ�
    int getCharacterDefence(); // ĳ���� ����
    int getCharacterExp(); // ĳ���� ����ġ
    int getCharacterGold(); // ĳ���� ��� ������

    // setter �Լ�
    void setCharacterName(string name); // ĳ���� �̸�
    void setCharacterLevel(int level); // ĳ���� ����
    bool setCharacterHp(int hp); // ĳ���� ü��
    void setCharacterPower(int power); // ĳ���� ���ݷ�
    void setCharacterDefence(int defence); // ĳ���� ����
    void setCharacterExp(int exp); // ĳ���� ����ġ
    void setCharacterGold(int gold); // ĳ���� ��� ������

protected:
    string name;
    int level;
    int hp;
    int power;
    int defence;
    int exp;
    int gold;

};
