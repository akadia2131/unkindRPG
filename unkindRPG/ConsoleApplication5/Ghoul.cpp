//Ghoul.cpp
#include "Ghoul.h"
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

Ghoul::Ghoul()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "구울";
	monsterlevel = 45;
	monstermaxhp = 250 + hprandom; 
	monsterhp = 250 + hprandom; 
	monsterpower = 35 + powerrandom; 
	monsterdefence = 0;
}

Ghoul::Ghoul(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Ghoul";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 0;
}


vector<string> Ghoul::Droptable(string) const
{
	const string ItemA = "구울의 이빨";
	const string ItemB = "구울의 검";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	return { RandomItem };
}