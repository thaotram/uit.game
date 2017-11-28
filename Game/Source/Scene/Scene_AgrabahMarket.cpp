#include "Scene_AgrabahMarket.h"
#include "../Object_Map/Map_AgrabahMarket.h"
#include "../../Define.h"

// Scene_AgrabahMarket
Scene_AgrabahMarket::Scene_AgrabahMarket() {
	float mapHeight = 686;
	float screenHeight = HEIGHT;
	
	mCameraPosition = {
		0, mapHeight - screenHeight
	};
	Add("1", new Map_AgrabahMarket());
}