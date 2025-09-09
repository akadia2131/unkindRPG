//Skeleton.cpp
#include "Skeleton.h"
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

Skeleton::Skeleton()
{
	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10


	name = "Skeleton";
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

Skeleton::Skeleton(string name)
{
	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10


	name = "Skeleton";
	setName(name);
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

vector<string> Skeleton::Droptable(int) const
{
	return { "½ºÄÌ·¹ÅæÀÇ »À", "½ºÄÌ·¹ÅæÀÇ °Ë" };
}

//void Goblin::attack()
//{
//	cout << "Goblin °¡ °ø°ÝÇß´Ù." << endl;
//}
