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

	monstername = "히드라";
	monsterlevel = 45;
	monstermaxhp = 400 + hprandom; 
	monsterhp = 400 + hprandom; 
	monsterpower = 45 + powerrandom;
	monsterdefence = 0;
}

Hydra::Hydra(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Hydra";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 0;
}

vector<string> Hydra::Droptable(string) const
{
	const string ItemA = "히드라의 이빨";
	const string ItemB = "히드라의 독침";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	return { RandomItem };
}
