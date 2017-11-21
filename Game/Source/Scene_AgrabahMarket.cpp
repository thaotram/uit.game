
#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Block.h"
#include "FinalUnit/Unit_Aladdin.h"
#include "Scene_AgrabahMarket_Map.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["1"] = new Scene_AgrabahMarket_Map();
	(*this)["3"] = new Unit_Aladdin();
}