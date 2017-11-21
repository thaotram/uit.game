#pragma once
#include "../Unit.h"

class Unit_Aladdin : public Unit {
private:
	Unit_Animation * animation;
	string * state;
public:
	Unit_Aladdin();
	bool UpdateUnit();
};