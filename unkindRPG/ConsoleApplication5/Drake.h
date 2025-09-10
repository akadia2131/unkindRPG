//Drake.h
#pragma once
#include "Monster.h"

class Drake : public Monster
{
public:
	Drake();
	Drake(string monstername);
	vector<string> Droptable(string) const override; // 드랍 아이템


	//	void attack() override;

};