//Ghoul.h
#pragma once
#include "Monster.h"

class Ghoul : public Monster
{
public:
	Ghoul();
	Ghoul(string name);
	vector<string> Droptable(int count = 2) const override; // ��� ������


	//	void attack() override;

};