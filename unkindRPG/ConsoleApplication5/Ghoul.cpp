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

	monstername = "Ghoul";
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom; //�ִ� ü�� 500 �κп� ĳ���� ������ ȣ�� �Ǿ���
	monsterhp = 500 * hprandom; //���� ü�� 500 �κп� ĳ���� ������ ȣ�� �Ǿ���
	monsterpower = 50 * powerrandom; // 50 �κп� ĳ���� ���� ȣ�� �Ǿ���
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
	const string ItemA = "������ �̻�";
	const string ItemB = "������ ��";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	cout << "����ǰ ŉ��!!" << endl;
	cout << RandomItem << endl;
	return { RandomItem };
}

//void Goblin::attack()
//{
//	cout << "Goblin �� �����ߴ�." << endl;
//}
