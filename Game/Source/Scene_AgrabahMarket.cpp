#include "Scene_AgrabahMarket.h"
#include "Unit_Aladdin.h"
#include "Unit_Peddler.h"
#include "Unit_EnemyExplosions.h"
#include "Unit_CivilianEnemies.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["2"] = new Unit_CivilianEnemies();
	(*this)["2"]->SetPosition(
		GameGlobal::GetWidth() / 2 * 1.f, 
		GameGlobal::GetScale() * 189
	);
	(*this)["2"]->GetAnimation()->SetState("straw_hit");
}
