//Monster.cpp
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Monster::Monster() 
{
    monstername = "Monster";
    monsterlevel = 0;
    monstermaxhp = 0;
    monsterhp = 0;
    monsterpower = 0;
    monsterdefence = 0;

}

Monster::Monster(string monstername)
{
    this->monstername = "Monster";
    this->monsterlevel = 0;
    this->monstermaxhp = 0;
    this->monsterhp = 0;
    this->monsterpower = 0;
    this->monsterdefence = 0;

}
void Monster::printMonsterStatus() 
{
    cout << "------------------------------------" << endl;
    cout << "[ 몬스터 능력치 ]" << endl;
    cout << "이름 : " << monstername << endl;
    cout << "Lv : " << monsterlevel << endl;
    cout << "최대 체력 : " << monstermaxhp << endl;
    cout << "현재 HP : " << monsterhp << endl;
    cout << "공격력: " << monsterpower << endl;
    cout << "방어력: " << monsterdefence << endl;
    cout << "------------------------------------" << endl;
}

static void random()
{
    static bool randoms = false;
    if (!randoms)
    {
        srand(static_cast<unsigned>(time(nullptr))); randoms = true;
    }
}

// 드랍 아이템
vector<string> Monster::Droptable(string) const
{
    return{};
}

// get
string Monster:: getMonsterName()
{
    return monstername;
}

int Monster::getMonsterLevel()
{
    return monsterlevel;
}

int Monster::getMonsterMaxHp()
{
    return monstermaxhp;
}

int Monster::getMonsterHp()
{
    return monsterhp;
}

int Monster::getMonsterPower()
{
    return monsterpower;
}

int Monster::getMonsterDefence()
{
    return monsterdefence;
}

//set
void Monster::setMonsterName(string monstername)
{
    this->monstername = monstername;
}

void Monster::setMonsterLevel(int monsterlevel)
{
    this->monsterlevel = monsterlevel;
}

void Monster::setMonsterMaxHp(int monstermaxhp)
{
    this->monstermaxhp = monstermaxhp;
}

bool Monster::setMonsterHp(int monsterhp)
{
    this->monsterhp = monsterhp;
    return this->monsterhp >= 1 ? true : false;
}

void Monster::setMonsterPower(int monsterpower)
{
    this->monsterpower = monsterpower;
}

void Monster::setMonsterDefence(int monsterdefence)
{
    this->monsterdefence = monsterdefence;
}


