#include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mCamera << D3DXVECTOR2{ 300, MAP_HEIGHT - HEIGHT };

	Add("1", new Object_Map_AgrabahMarket_Back());
	Add("2", new Object_Unit_Aladdin());
}