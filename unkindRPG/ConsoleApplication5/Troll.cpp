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

	name = "Troll";
	level = 45;
	hp = 500 * hprandom; //캐릭터 레벨 호출
	power = 50 * powerrandom; // 캐릭터 레벨 호출
	defence = 40;
}

Troll::Troll(string name)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	name = "Troll";
	setName(name);
	level = 45;
	hp = 500 * hprandom;
	power = 50 * powerrandom;
	defence = 40;
}

vector<string> Troll::Droptable(int) const
{
	return { "트롤의 이빨", "트롤의 검" };
}

//void Troll::attack()
//{
//	cout << "Orc 가 공격했다." << endl;
//}
