//Slime.cpp
#include "Slime.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

static void random()
{
	static bool randoms = false;
	if (!randoms)
	{
		srand(static_cast<unsigned>(time(nullptr))); randoms = true;
	}
}

Slime::Slime()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "Slime";
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom; //최대 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterhp = 500 * hprandom; //현재 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterpower = 50 * powerrandom; // 50 부분에 캐릭터 레벨 호출 되야함
	monsterdefence = 40;
}

Slime::Slime(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Slime";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 40;
}

vector<string> Slime::Droptable(string) const
{
	const string ItemA = "슬라임의 구슬";
	const string ItemB = "슬라임의 액체";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	cout << "전리품 흭득!!" << endl;
	cout << RandomItem << endl;
	return { RandomItem };
}

//void Slime::attack()
//{
//	cout << "Orc 가 공격했다." << endl;
//}
