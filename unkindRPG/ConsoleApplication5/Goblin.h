//Goblin.h
#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(string monstername);
	vector<string> Droptable(string) const override; // ��� ������


//	void attack() override;

};