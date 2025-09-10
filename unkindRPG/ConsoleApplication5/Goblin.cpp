//Goblin.cpp
#include "Goblin.h"
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

Goblin::Goblin()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "Goblin";
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom; //최대 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterhp = 500 * hprandom; //현재 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterpower = 50 * powerrandom; // 50 부분에 캐릭터 레벨 호출 되야함
	monsterdefence = 40;
}

Goblin::Goblin(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Goblin";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 40;
}

vector<string> Goblin::Droptable(string) const
{
	const string ItemA = "고블린의 검";
	const string ItemB = "고블린의 방패";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	cout << "전리품 흭득!!" << endl;
	cout << RandomItem << endl;
	return { RandomItem };
}

//void Goblin::attack()
//{
//	cout << "Goblin 가 공격했다." << endl;
//}
