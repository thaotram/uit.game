
#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Camel.h"
#include "FinalUnit/Unit_Aladdin.h"
#include "FinalUnit/Unit_Status.h"
#include "FinalUnit/Unit_Guards.h"

#include "Map_AgrabahMarket.h"


AgrabahMarket::AgrabahMarket() {
	//(*this)["1"] = new Map_AgrabahMarket();
	(*this)["3"] = new Unit_Aladdin();
	//(*this)["4"] = new Unit_Status();
}