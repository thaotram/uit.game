#pragma once
#include "../Unit.h"

class Unit_Aladdin : public Unit {
private:
	string * state;
public:
	Unit_Aladdin();
	bool UpdateUnit();
};