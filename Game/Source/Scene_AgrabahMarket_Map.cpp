#pragma once
#include "Scene_AgrabahMarket_Map.h"

Scene_AgrabahMarket_Map::Scene_AgrabahMarket_Map() : Unit("AgrabahMarket") {
	this->Set(
		new Unit_Entity({ 0, 166 }, "back")
	);
}

bool Scene_AgrabahMarket_Map::UpdateUnit() {
	return false;
}
