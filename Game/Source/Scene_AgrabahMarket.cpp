#include "Scene_AgrabahMarket.h"
#include "Unit_Aladdin.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["2"] = new Unit_Aladdin();
}
