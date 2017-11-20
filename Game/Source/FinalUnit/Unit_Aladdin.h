#pragma once
#include "../Unit.h"
#include "../GameInput.h"

class Unit_Aladdin : public Unit {
private:
	int hp;
public:
	Unit_Aladdin();
	bool UpdateUnit();
};