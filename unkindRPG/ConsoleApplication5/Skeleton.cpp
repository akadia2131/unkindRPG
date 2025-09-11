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

	monstername = "½ºÄÌ·¹Åæ";
	monsterlevel = 45;
	monstermaxhp = 550 + hprandom;
	monsterhp = 550 + hprandom; 
	monsterpower = 0 + powerrandom;
	monsterdefence = 0;
}

Skeleton::Skeleton(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Skeleton";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 0;
}

vector<string> Skeleton::Droptable(string) const
{
	const string ItemA = "½ºÄÌ·¹ÅæÀÇ ÀÌ»¡";
	const string ItemB = "½ºÄÌ·¹ÅæÀÇ °Ë";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;

	return { RandomItem };
}