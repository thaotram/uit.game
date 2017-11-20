
#include "Scene_AgrabahMarket.h"
#include "FinalUnit/Unit_Block.h"
#include "FinalUnit/Unit_Aladdin.h"
//#include "Debug/Unit_Debug.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["3"] = new Unit_Aladdin();
}