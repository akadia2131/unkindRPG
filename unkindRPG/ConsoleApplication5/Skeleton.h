//Skeleton.h
#pragma once
#include "Monster.h"

class Skeleton : public Monster
{
public:
	Skeleton();
	Skeleton(string monstername);
	vector<string> Droptable(string) const override; // ��� ������

	//	void attack() override;

};