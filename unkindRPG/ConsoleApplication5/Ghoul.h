//Ghoul.h
#pragma once
#include "Monster.h"

class Ghoul : public Monster
{
public:
	Ghoul();
	Ghoul(string monstername);
	vector<string> Droptable(string) const override; // ��� ������


	//	void attack() override;

};