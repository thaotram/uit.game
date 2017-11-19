
#include "Scene_AgrabahMarket.h"
#include "Unit_Aladdin.h"
#include "Unit_Peddler.h"
#include "Unit_EnemyExplosions.h"
#include "Unit_CivilianEnemies.h"
#include "Unit_Abu.h"

AgrabahMarket::AgrabahMarket() {
	(*this)["2"] = new Unit_Aladdin();
}
