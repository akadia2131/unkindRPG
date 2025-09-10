//Ghoul.h
#pragma once
#include "Monster.h"

class Ghoul : public Monster
{
public:
	Ghoul();
	Ghoul(string monstername);
	vector<string> Droptable(string) const override; // 드랍 아이템


	//	void attack() override;

};