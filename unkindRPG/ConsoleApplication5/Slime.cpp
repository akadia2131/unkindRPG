//Slime.cpp
#include "Slime.h"
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

Slime::Slime()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "슬라임";
	monsterlevel = 45;
	monstermaxhp = 150 + hprandom;
	monsterhp = 150 + hprandom; 
	monsterpower = 10 + powerrandom;
	monsterdefence = 0;
}

Slime::Slime(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Slime";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 0;
}

vector<string> Slime::Droptable(string) const
{
	const string ItemA = "슬라임의 구슬";
	const string ItemB = "슬라임의 액체";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	return { RandomItem };
}
