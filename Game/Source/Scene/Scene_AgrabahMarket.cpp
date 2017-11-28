#include "Scene_AgrabahMarket.h"
#include "../Object_Map/Map_AgrabahMarket.h"

// Scene_AgrabahMarket
Scene_AgrabahMarket::Scene_AgrabahMarket() {
	Add("1", new Map_AgrabahMarket());
}