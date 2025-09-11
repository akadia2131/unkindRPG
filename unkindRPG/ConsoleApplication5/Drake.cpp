//Drake.cpp
#include "Drake.h"
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

Drake::Drake()
{

	random();
	int hprandom = 20 + rand() % 11; // 20 ~ 30
	int powerrandom = 5 + rand() % 6; // 5 ~ 10

	monstername = "�巹��ũ";
	monsterlevel = 45;
	monstermaxhp = 300 + hprandom;
	monsterhp = 300 + hprandom; 
	monsterpower = 40 + powerrandom; 
	monsterdefence = 0;
}

Drake::Drake(string monstername)
{

	random();
	int hprandom = 20 + rand() % 11;
	int powerrandom = 5 + rand() % 6;

	monstername = "Drake";
	setMonsterName(monstername);
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom;
	monsterhp = 500 * hprandom;
	monsterpower = 50 * powerrandom;
	monsterdefence = 0;
}

vector<string> Drake::Droptable(string) const
{
	const string ItemA = "�巹��ũ�� �̻�";
	const string ItemB = "�巹��ũ�� ����";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	return { RandomItem };
}