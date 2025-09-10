//Hydra.h
#pragma once
#include "Monster.h"

class Hydra : public Monster
{
public:
	Hydra();
	Hydra(string monstername);
	vector<string> Droptable(string) const override; // 드랍 아이템


	//	void attack() override;

};