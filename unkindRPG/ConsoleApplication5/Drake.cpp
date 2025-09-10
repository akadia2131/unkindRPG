//Drake.cpp
#include "Drake.h"
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

Drake::Drake()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "Drake";
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom; //최대 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterhp = 500 * hprandom; //현재 체력 500 부분에 캐릭터 레벨이 호출 되야함
	monsterpower = 50 * powerrandom; // 50 부분에 캐릭터 레벨 호출 되야함
	monsterdefence = 0;
}

Drake::Drake(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Drake";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 0;
}

vector<string> Drake::Droptable(string) const
{
	const string ItemA = "드레이크의 이빨";
	const string ItemB = "드레이크의 날개";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	cout << "전리품 흭득!!" << endl;
	cout << RandomItem << endl;
	return { RandomItem };
}

//void Goblin::attack()
//{
//	cout << "Goblin 가 공격했다." << endl;
//}
