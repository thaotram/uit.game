#pragma once
#include "Map_AgrabahMarket.h"

Map_AgrabahMarket::Map_AgrabahMarket() : Unit("AgrabahMarket") {
	mAnimation.SetState("back");
	mPosition = { 0,224 };
}

bool Map_AgrabahMarket::AutoNextFrame() {
	return false;
}