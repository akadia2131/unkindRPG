//Character.h
#pragma once
#include <string>

using namespace std;

class Character
{
public:
    Character();
    Character(string charactername); // 몬스터 이름

    // virtual void attack() = 0; // 몬스터가 공격하기 미구현
    void printCharacterStatus(); // 몬스터 스탯


    // getter 함수
    string getCharacterName(); // 캐릭터 이름
    int getCharacterLevel();  // 캐릭터 레벨
    int getCharacterMaxHp(); // 캐릭터 최대 체력
    int getCharacterHp(); // 캐릭터 현재 체력
    int getCharacterPower(); // 캐릭터 공격력
    int getCharacterDefence(); // 캐릭터 방어력
    int getCharacterExp(); // 캐릭터 경험치
    int getCharacterGold(); // 캐릭터 골드 소지금

    // setter 함수
    void setCharacterName(string charactername); // 캐릭터 이름
    void setCharacterLevel(int characterlevel); // 캐릭터 레벨
    void setCharacterMaxHp(int charactermaxhp); // 캐릭터 최대 체력
    bool setCharacterHp(int characterhp); // 캐릭터 체력
    void setCharacterPower(int characterpower); // 캐릭터 공격력
    void setCharacterDefence(int characterdefence); // 캐릭터 방어력
    void setCharacterExp(int characterexp); // 캐릭터 경험치
    void setCharacterGold(int charactergold); // 캐릭터 골드 소지금

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
