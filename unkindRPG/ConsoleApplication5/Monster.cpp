//Monster.cpp
#include "Monster.h"
#include <iostream>

Monster::Monster() 
{
    name = "Monster";
    level = 0;
    hp = 0;
    power = 0;
    defence = 0;

}

Monster::Monster(string name) 
{
    this-> name = "Monster";
    this-> level = 0;
    this-> hp = 0;
    this-> power = 0;
    this-> defence = 0;

}
void Monster::printMonsterStatus() 
{
    cout << "------------------------------------" << endl;
    cout << "[ 몬스터 능력치 ]" << endl;
    cout << "이름 : " << name << endl;
    cout << "Lv : " << level << endl;
    cout << "HP : " << hp << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "------------------------------------" << endl;
}

// get
string Monster:: getName()
{
    return name;
}

int Monster::getLevel()
{
    return level;
}

int Monster::getHP()
{
    return hp;
}

int Monster::getPower()
{
    return power;
}

int Monster::getDefence()
{
    return defence;
}

//set
void Monster::setName(string name)
{
    this-> name = name;
}

void Monster::setLevel(int level)
{
    this->level = level;
}

bool Monster::setHP(int hp)
{
    this-> hp = hp;
    return this-> hp >= 1 ? true : false;
}

void Monster::setPower(int power)
{
    this->power = power;
}

void Monster::setDefence(int defence)
{
    this->defence = defence;
}

// 드랍 아이템
vector<string> Monster::Droptable(int) const 
{
    return {};
}
