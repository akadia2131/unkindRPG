//Drake.h
#pragma once
#include "Monster.h"

class Drake : public Monster
{
public:
	Drake();
	Drake(string name);
	vector<string> Droptable(int count = 2) const override; // ��� ������


	//	void attack() override;

};