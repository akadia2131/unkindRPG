//Orc.h
#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
	Orc();
	Orc(string name);
	vector<string> Droptable(int count = 2) const override; // ��� ������

//	void attack() override;

};