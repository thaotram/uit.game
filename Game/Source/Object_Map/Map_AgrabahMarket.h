#pragma once
#include "../Object/Object.h"

class Map_AgrabahMarket : public Object {
public:
	Map_AgrabahMarket();
	void AfterAddToScene();
	void UnitRender(float delay);
};