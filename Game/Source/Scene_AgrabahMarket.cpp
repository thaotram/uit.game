
#include "Scene_AgrabahMarket.h"
#include "Unit_Aladdin.h"
#include "Unit_Peddler.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["2"] = new Unit_Aladdin();
	(*this)["2"]->SetPosition(
		GameGlobal::GetWidth() / 2 * 1.f, 
		200
	);
}
