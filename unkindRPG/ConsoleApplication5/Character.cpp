//Character.cpp
#include "Character.h"
#include <iostream>

Character::Character()
{
    charactername = "Character";
    characterlevel = 0;
    charactermaxhp = 0;
    characterhp = 0;
    characterpower = 0;
    characterdefence = 0;
    characterexp = 0;
    charactergold = 0;
}

Character::Character(string charactername)
{
    this->charactername = "Character";
    this->characterlevel = 0;
    this->charactermaxhp = 0;
    this->characterhp = 0;
    this->characterpower = 0;
    this->characterdefence = 0;
    this->characterexp = 0;
    this->charactergold = 0;
}
void Character::printCharacterStatus()
{
    cout << "------------------------------------" << endl;
    cout << "[ ĳ���� �ɷ�ġ ]" << endl;
    cout << "�̸� : " << charactername << endl;
    cout << "Lv : " << characterlevel << endl;
    cout << "�ִ� ü�� : " << charactermaxhp << endl;
    cout << "���� HP : " << characterhp << endl;
    cout << "���ݷ�: " << characterpower << endl;
    cout << "����: " << characterdefence << endl;
    cout << "����: " << characterdefence << endl;
    cout << "------------------------------------" << endl;
}

// get
string Character::getCharacterName()
{
    return charactername;
}

int Character::getCharacterLevel()
{
    return characterlevel;
}

int Character::getCharacterMaxHp()
{
    return charactermaxhp;
}

int Character::getCharacterHp()
{
    return characterhp;
}

int Character::getCharacterPower()
{
    return characterpower;
}

int Character::getCharacterDefence()
{
    return characterdefence;
}

int Character::getCharacterExp()
{
    return characterexp;
}

int Character::getCharacterGold()
{
    return charactergold;
}

//set
void Character::setCharacterName(string charactername)
{
    this->charactername = charactername;
}

void Character::setCharacterLevel(int characterlevel)
{
    this->characterlevel = characterlevel;
}

void Character::setCharacterMaxHp(int charactermaxhp)
{
    this->characterlevel = charactermaxhp;
}

bool Character::setCharacterHp(int characterhp)
{
    this->characterhp = characterhp;
    return this->characterhp >= 1 ? true : false;
}

void Character::setCharacterPower(int characterpower)
{
    this->characterpower = characterpower;
}

void Character::setCharacterDefence(int characterdefence)
{
    this->characterdefence = characterdefence;
}

void Character::setCharacterExp(int characterexp)
{
    this->characterexp = characterexp;
}

void Character::setCharacterGold(int charactergold)
{
    this->charactergold = charactergold;
}