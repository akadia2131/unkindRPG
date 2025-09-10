//Monster.h
#pragma once
#include <string>
#include <vector>

using namespace std;

class Monster
{
public:
    Monster();
    Monster(string monstername); // 몬스터 이름

    // virtual void attack() = 0; // 몬스터가 공격하기 미구현
    void printMonsterStatus(); // 몬스터 스탯
    virtual vector<string> Droptable(string) const; // 드랍 테이블

    // void takeDamage(int damage);
    
    // getter 함수
    string getMonsterName(); // 몬스터 이름
    int getMonsterLevel();  // 몬스터 레벨
    int getMonsterMaxHp(); // 몬스터 최대 체력
    int getMonsterHp(); // 몬스터 현재 체력
    int getMonsterPower(); // 몬스터 공격력
    int getMonsterDefence(); // 몬스터 방어력

    // setter 함수
    void setMonsterName(string monstername); // 몬스터 이름
    void setMonsterLevel(int monsterlevel); // 몬스터 레벨
    void setMonsterMaxHp(int monstermaxhp); // 몬스터 최대 체력
    bool setMonsterHp (int monsterhp); // 몬스터 체력
    void setMonsterPower (int monsterpower); // 몬스터 공격력
    void setMonsterDefence(int monsterdefence); // 몬스터 방어력


protected:
    string monstername;
    int monsterlevel;
    int monstermaxhp;
    int monsterhp;
    int monsterpower;
    int monsterdefence;
  
};
