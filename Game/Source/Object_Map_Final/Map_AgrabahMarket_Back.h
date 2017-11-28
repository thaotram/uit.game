#pragma once
#include "../Object_Map/Map.h"

class Map_AgrabahMarket_Back : public Map {
public:
	Map_AgrabahMarket_Back();
	void AfterAddToScene();
	void BeforeRender(float delay);
};