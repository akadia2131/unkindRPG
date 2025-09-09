//Slime.cpp
#include "Slime.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void random()
{
	static bool randoms = false;
	if (!randoms)
	{
		srand(static_cast<unsigned>(time(nullptr))); randoms = true;
	}
}

using namespace std;

Slime::Slime()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	name = "Slime";
	level = 1;
	hp = 50 * hprandom;
	power = 5 * powerrandom;
	defence = 0;
}

Slime::Slime(string name)
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	name = "Slime";
	setName(name);
	level = 1;
	hp = 50 * hprandom;
	power = 5 * powerrandom;
	defence = 0;
}

vector<string> Slime::Droptable(int) const
{
	return { "슬라임 구슬", "슬라임 액체" };
}

//void Slime::attack()
//{
//	cout << "Orc 가 공격했다." << endl;
//}
