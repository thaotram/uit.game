#include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Map_AgrabahMarket_Back.h"
#include "../../Define.h"

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mCameraPosition = { 0, MAP_HEIGHT - HEIGHT };

	Add("1", new Object_Map_AgrabahMarket_Back());
}