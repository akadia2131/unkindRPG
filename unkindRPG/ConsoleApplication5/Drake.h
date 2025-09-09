//Drake.h
#pragma once
#include "Monster.h"

class Drake : public Monster
{
public:
	Drake();
	Drake(string name);
	vector<string> Droptable(int count = 2) const override; // 드랍 아이템


	//	void attack() override;

};