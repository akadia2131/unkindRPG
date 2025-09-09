//Monster.h
#pragma once
#include <string>
#include <vector>

using namespace std;

class Monster
{
public:
    Monster();
    Monster(string name); // 몬스터 이름

    // virtual void attack() = 0; // 몬스터가 공격하기 미구현
    void printMonsterStatus(); // 몬스터 스탯
    virtual vector<string> Droptable(int count = 0) const; // 드랍 테이블

    // void takeDamage(int damage);
    
    // getter 함수
    string getName(); // 몬스터 이름
    int getLevel();  // 몬스터 레벨
    int getHP(); // 몬스터 체력
    int getPower(); // 몬스터 공격력
    int getDefence(); // 몬스터 방어력

    // setter 함수
    void setName(string name); // 몬스터 이름
    void setLevel(int level); // 몬스터 레벨
    bool setHP (int hp); // 몬스터 체력
    void setPower (int power); // 몬스터 공격력
    void setDefence(int defence); // 몬스터 방어력


protected:
    string name;  
    int level;
    int hp;
    int power;
    int defence;
  
};
