//Character.h
#pragma once
#include <string>

using namespace std;

class Character
{
public:
    Character();
    Character(string charactername); // ���� �̸�

    // virtual void attack() = 0; // ���Ͱ� �����ϱ� �̱���
    void printCharacterStatus(); // ���� ����


    // getter �Լ�
    string getCharacterName(); // ĳ���� �̸�
    int getCharacterLevel();  // ĳ���� ����
    int getCharacterMaxHp(); // ĳ���� �ִ� ü��
    int getCharacterHp(); // ĳ���� ���� ü��
    int getCharacterPower(); // ĳ���� ���ݷ�
    int getCharacterDefence(); // ĳ���� ����
    int getCharacterExp(); // ĳ���� ����ġ
    int getCharacterGold(); // ĳ���� ��� ������

    // setter �Լ�
    void setCharacterName(string charactername); // ĳ���� �̸�
    void setCharacterLevel(int characterlevel); // ĳ���� ����
    void setCharacterMaxHp(int charactermaxhp); // ĳ���� �ִ� ü��
    bool setCharacterHp(int characterhp); // ĳ���� ü��
    void setCharacterPower(int characterpower); // ĳ���� ���ݷ�
    void setCharacterDefence(int characterdefence); // ĳ���� ����
    void setCharacterExp(int characterexp); // ĳ���� ����ġ
    void setCharacterGold(int charactergold); // ĳ���� ��� ������

protected:
    string charactername;
    int characterlevel;
    int charactermaxhp;
    int characterhp;
    int characterpower;
    int characterdefence;
    int characterexp;
    int charactergold;

};
