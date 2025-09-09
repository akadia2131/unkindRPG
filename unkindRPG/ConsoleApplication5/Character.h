//Character.h
#pragma once
#include <string>

using namespace std;

class Character
{
public:
    Character();
    Character(string name); // 몬스터 이름

    // virtual void attack() = 0; // 몬스터가 공격하기 미구현
    void printCharacterStatus(); // 몬스터 스탯


    // getter 함수
    string getCharacterName(); // 캐릭터 이름
    int getCharacterLevel();  // 캐릭터 레벨
    int getCharacterHP(); // 캐릭터 체력
    int getCharacterPower(); // 캐릭터 공격력
    int getCharacterDefence(); // 캐릭터 방어력
    int getCharacterExp(); // 캐릭터 경험치
    int getCharacterGold(); // 캐릭터 골드 소지금

    // setter 함수
    void setCharacterName(string name); // 캐릭터 이름
    void setCharacterLevel(int level); // 캐릭터 레벨
    bool setCharacterHp(int hp); // 캐릭터 체력
    void setCharacterPower(int power); // 캐릭터 공격력
    void setCharacterDefence(int defence); // 캐릭터 방어력
    void setCharacterExp(int exp); // 캐릭터 경험치
    void setCharacterGold(int gold); // 캐릭터 골드 소지금

protected:
    string name;
    int level;
    int hp;
    int power;
    int defence;
    int exp;
    int gold;

};
