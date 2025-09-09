//Orc.cpp
#include "Orc.h"
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

Orc::Orc()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	name = "Orc";
	level = 30;
	hp = 400 * hprandom;
	power = 30 * powerrandom;
	defence = 40;
}

Orc::Orc(string name)
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	name = "Orc";
	setName(name);
	level = 30;
	hp = 400 * hprandom;
	power = 30 * powerrandom;
	defence = 40;
}

vector<string> Orc::Droptable(int) const
{
	return { "오크의 이빨", "오크의 검" };
}

//void Orc::attack()
//{
//	cout << "Orc 가 공격했다." << endl;
//}
