//Slime.h
#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
	Slime();
	Slime(string name);
	vector<string> Droptable(int count = 2) const override; // ��� ������

//	void attack() override;

};