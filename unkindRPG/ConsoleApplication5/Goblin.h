//Goblin.h
#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(string name);
	vector<string> Droptable(int count = 2) const override; // ��� ������


//	void attack() override;

};