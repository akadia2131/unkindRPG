//Skeleton.h
#pragma once
#include "Monster.h"

class Skeleton : public Monster
{
public:
	Skeleton();
	Skeleton(string name);
	vector<string> Droptable(int count = 2) const override; // 드랍 아이템

	//	void attack() override;

};