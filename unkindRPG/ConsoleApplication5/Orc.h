//Orc.h
#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
	Orc();
	Orc(string monsternamem);
	vector<string> Droptable(string) const override; // ��� ������

//	void attack() override;

};