//Troll.cpp
#include "Troll.h"
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

Troll::Troll()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "Troll";
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom; //최대 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterhp = 500 * hprandom; //현재 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterpower = 50 * powerrandom; // 50 부분에 캐릭터 레벨 호출 되야함
	monsterdefence = 40;
}

Troll::Troll(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Troll";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 40;
}

vector<string> Troll::Droptable(string) const
{
	const string ItemA = "트롤의 이빨";
	const string ItemB = "트롤의 검";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;

	cout << "전리품 흭득!!" << endl;
	cout << RandomItem << endl;

	return { RandomItem };
}

//void Troll::attack()
//{
//	cout << "Orc 가 공격했다." << endl;
//}
