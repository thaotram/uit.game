#pragma once
#include "Unit.h"

class Map_AgrabahMarket : public Unit {
public:
	Map_AgrabahMarket();
	void AfterAddToScene();
	void UnitRender(float dt);
};