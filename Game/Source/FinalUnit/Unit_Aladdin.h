#pragma once
#include "../Unit.h"
#include "../Scene.h"

class Unit_Aladdin : public Unit {
private:
	string * state;
public:
	Unit_Aladdin();
	void UnitUpdateBeforeNextFrame();
};