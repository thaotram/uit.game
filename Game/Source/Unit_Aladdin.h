#pragma once
#include "Unit.h"
class Unit_Aladdin : public Unit {
private:
	int hp;
	float x;
public:
	Unit_Aladdin();
	void BeforeUpdateUnit();
};