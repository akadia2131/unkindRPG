//Orc.cpp
#include "Orc.h"
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

Orc::Orc()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "오크";
	monsterlevel = 45;
	monstermaxhp = 200 + hprandom; 
	monsterhp = 200 + hprandom; 
	monsterpower = 100 + powerrandom; 
	monsterdefence = 0;
}

Orc::Orc(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Orc";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 40;
}

vector<string> Orc::Droptable(string) const
{
	const string ItemA = "오크의 이빨";
	const string ItemB = "오크의 검";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	return { RandomItem };
}