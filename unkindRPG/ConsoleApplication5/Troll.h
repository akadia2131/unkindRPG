//Troll.h
#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
	Troll();
	Troll(string name);
	vector<string> Droptable(int count = 2) const override; // 드랍 아이템

//	void attack() override;

};