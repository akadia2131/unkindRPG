//Troll.h
#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
	Troll();
	Troll(string name);
	vector<string> Droptable(int count = 2) const override; // ��� ������

//	void attack() override;

};