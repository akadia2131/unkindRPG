//Hydra.h
#pragma once
#include "Monster.h"

class Hydra : public Monster
{
public:
	Hydra();
	Hydra(string name);
	vector<string> Droptable(int count = 2) const override; // ��� ������


	//	void attack() override;

};