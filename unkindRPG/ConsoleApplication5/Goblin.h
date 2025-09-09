//Goblin.h
#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(string name);
	vector<string> Droptable(int count = 2) const override; // 드랍 아이템


//	void attack() override;

};