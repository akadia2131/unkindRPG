//Troll.h
#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
	Troll();
	Troll(string monstername);
	vector<string> Droptable(string) const override; // 드랍 아이템

//	void attack() override;

};