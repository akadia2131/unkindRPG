//Drake.h
#pragma once
#include "Monster.h"

class Drake : public Monster
{
public:
	Drake();
	Drake(string monstername);
	vector<string> Droptable(string) const override; // ��� ������


	//	void attack() override;

};