
#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Block.h"
#include "FinalUnit/Unit_Aladdin.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["2"] = new Unit_Block();
	(*this)["3"] = new Unit_Aladdin();

}
