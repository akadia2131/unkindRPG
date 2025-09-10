//Slime.h
#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
	Slime();
	Slime(string monstername);
	vector<string> Droptable(string) const override; // 드랍 아이템

//	void attack() override;

};