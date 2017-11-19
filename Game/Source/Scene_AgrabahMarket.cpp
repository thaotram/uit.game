
#include "Scene_AgrabahMarket.h"
#include "Unit_Aladdin.h"
#include "Unit_Peddler.h"
#include "Unit_EnemyExplosions.h"
#include "Unit_CivilianEnemies.h"
#include "Unit_Abu.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["2"] = new Unit_Abu();
	(*this)["2"]->SetPosition(
		GameGlobal::GetWidth() / 2 * 1.f, 
		200
	);
	(*this)["2"]->GetAnimation()->SetState("abu_levelcomplete");
}
