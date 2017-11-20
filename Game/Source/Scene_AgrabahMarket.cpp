
#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Block.h"
#include "FinalUnit/Unit_Aladdin.h"
#include "Debug/Unit_Debug.h"

AgrabahMarket::AgrabahMarket() {
	//(*this)["2"] = new Unit_Block();
	(*this)["3"] = new Unit_Aladdin();
	
	//(*this)["5"] = new Unit_Debug();
}
