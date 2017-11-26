
#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Aladdin.h"

AgrabahMarket::AgrabahMarket() {
	//(*this)["1"] = new Map_AgrabahMarket();
	(*this)["3"] = new Unit_Aladdin();
	//(*this)["4"] = new Unit_Status();
}