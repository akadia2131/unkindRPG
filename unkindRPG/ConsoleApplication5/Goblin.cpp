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


	name = "Goblin";
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

Goblin::Goblin(string name)
{
	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10


	name = "Goblin";
	setName(name);
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

vector<string> Goblin::Droptable(int) const 
{
	return { "고블린의 이빨", "고블린의 검" };
}

//void Goblin::attack()
//{
//	cout << "Goblin 가 공격했다." << endl;
//}
