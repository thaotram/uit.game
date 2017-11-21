
#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Camel.h"
#include "FinalUnit/Unit_Aladdin.h"
#include "FinalUnit/Unit_Guards.h"

#include "Scene_AgrabahMarket_Map.h"


AgrabahMarket::AgrabahMarket() {
	(*this)["1"] = new Scene_AgrabahMarket_Map();
	(*this)["3"] = new Unit_Aladdin();
	(*this)["4"] = new Unit_Guards();
}