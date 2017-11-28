#pragma once
#include "../Object_Map/Map.h"

class Map_AgrabahMarket : public Map {
public:
	Map_AgrabahMarket();
	void AfterAddToScene();
	void BeforeRender(float delay);
};