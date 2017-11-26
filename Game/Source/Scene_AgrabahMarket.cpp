#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Aladdin.h"
#include "Map_AgrabahMarket.h"

// Scene_AgrabahMarket
Scene_AgrabahMarket::Scene_AgrabahMarket() {
	Add("1", new Map_AgrabahMarket());
	//Add("3", new Unit_Aladdin());
}