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

	monstername = "Slime";
	monsterlevel = 45;
	monstermaxhp = 500 * hprandom; //�ִ� ü�� 500 �κп� ĳ���� ������ ȣ�� �Ǿ���
	monsterhp = 500 * hprandom; //���� ü�� 500 �κп� ĳ���� ������ ȣ�� �Ǿ���
	monsterpower = 50 * powerrandom; // 50 �κп� ĳ���� ���� ȣ�� �Ǿ���
	monsterdefence = 40;
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
	monsterdefence = 40;
}

vector<string> Slime::Droptable(string) const
{
	const string ItemA = "�������� ����";
	const string ItemB = "�������� ��ü";

	const string RandomItem = (rand() % 2) ? ItemA : ItemB;
	cout << "����ǰ ŉ��!!" << endl;
	cout << RandomItem << endl;
	return { RandomItem };
}

//void Slime::attack()
//{
//	cout << "Orc �� �����ߴ�." << endl;
//}
