#pragma once
#include "Unit.h"
class Unit_Aladdin : public Unit {
private:
	int hp;
public:
	Unit_Aladdin();
	bool UpdateAnimation();
};