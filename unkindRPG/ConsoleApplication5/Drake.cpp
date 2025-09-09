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


	name = "Drake";
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

Drake::Drake(string name)
{
	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10


	name = "Drake";
	setName(name);
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

vector<string> Drake::Droptable(int) const
{
	return { "드레이크의 이빨", "드레이크의 날개" };
}

//void Goblin::attack()
//{
//	cout << "Goblin 가 공격했다." << endl;
//}
