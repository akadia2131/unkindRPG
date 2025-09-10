//Skeleton.h
#pragma once
#include "Monster.h"

class Skeleton : public Monster
{
public:
	Skeleton();
	Skeleton(string monstername);
	vector<string> Droptable(string) const override; // 드랍 아이템

	//	void attack() override;

};