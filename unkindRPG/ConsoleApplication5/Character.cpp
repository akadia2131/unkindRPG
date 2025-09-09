//Character.cpp
#include "Character.h"
#include <iostream>

Character::Character()
{
    name = "Monster";
    level = 0;
    hp = 0;
    power = 0;
    defence = 0;

}

Character::Character(string name)
{
    this->name = "Character";
    this->level = 0;
    this->hp = 0;
    this->power = 0;
    this->defence = 0;

}
void Character::printCharacterStatus()
{
    cout << "------------------------------------" << endl;
    cout << "[ 캐릭터 능력치 ]" << endl;
    cout << "이름 : " << name << endl;
    cout << "Lv : " << level << endl;
    cout << "HP : " << hp << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "------------------------------------" << endl;
}

// get
string Character::getCharacterName()
{
    return name;
}

int Character::getCharacterLevel()
{
    return level;
}

int Character::getCharacterHP()
{
    return hp;
}

int Character::getCharacterPower()
{
    return power;
}

int Character::getCharacterDefence()
{
    return defence;
}

int Character::getCharacterExp()
{
    return exp;
}

int Character::getCharacterGold()
{
    return gold;
}

//set
void Character::setCharacterName(string name)
{
    this->name = name;
}

void Character::setCharacterLevel(int level)
{
    this->level = level;
}

bool Character::setCharacterHp(int hp)
{
    this->hp = hp;
    return this->hp >= 1 ? true : false;
}

void Character::setCharacterPower(int power)
{
    this->power = power;
}

void Character::setCharacterDefence(int defence)
{
    this->defence = defence;
}

