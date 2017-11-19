
#include "Scene_AgrabahMarket.h"
#include "Unit_Block.h"
#include "Unit_Aladdin.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["2"] = new Unit_Block();
	(*this)["3"] = new Unit_Aladdin();

}
