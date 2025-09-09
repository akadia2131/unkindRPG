//Hydra.cpp
#include "Hydra.h"
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

Hydra::Hydra()
{
	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10


	name = "Hydra";
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

Hydra::Hydra(string name)
{
	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10


	name = "Hydra";
	setName(name);
	level = 5;
	hp = 200 * hprandom;
	power = 20 * powerrandom;
	defence = 10;
}

vector<string> Hydra::Droptable(int) const
{
	return { "히드라의 독침", "히드라의 꼬리" };
}

//void Goblin::attack()
//{
//	cout << "Goblin 가 공격했다." << endl;
//}
