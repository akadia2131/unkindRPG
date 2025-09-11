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

	monstername = "고블린";
	monsterlevel = 45;
	monstermaxhp = 150 + hprandom; 
	monsterhp = 15 + hprandom; 
	monsterpower = 25 + powerrandom;
	monsterdefence = 0;
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
	monsterdefence = 0;
}

vector<string> Goblin::Droptable(string) const
{
	const string ItemA = "고블린의 검";
	const string ItemB = "고블린의 방패";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	return { RandomItem };
}