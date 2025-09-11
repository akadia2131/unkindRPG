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

	monstername = "트롤";
	monsterlevel = 45;
	monstermaxhp = 700 + hprandom;
	monsterhp = 700 + hprandom; 
	monsterpower = 15 + powerrandom;
	monsterdefence = 0;
}

Troll::Troll(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Troll";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 0;
}

vector<string> Troll::Droptable(string) const
{
	const string ItemA = "트롤의 이빨";
	const string ItemB = "트롤의 검";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	return { RandomItem };
}