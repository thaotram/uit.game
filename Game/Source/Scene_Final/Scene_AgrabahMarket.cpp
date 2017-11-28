#include "Scene_AgrabahMarket.h"
#include "../Object_Map/Map_AgrabahMarket_Back.h"
#include "../../Define.h"

#define MAP_HEIGHT = 686;

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mCameraPosition = {
		0, MAP_HEIGHT - HEIGHT
	};

	Add("1", new Map_AgrabahMarket_Back());
}