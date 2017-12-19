#include "Scene_AgrabahMarket.h"

#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"

#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../Object_Unit_Final/Object_Unit_Static_Abubonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Static_Black_Magic_Lamp.h"
#include "../Object_Unit_Final/Object_Unit_Static_Block_Drop.h"
#include "../Object_Unit_Final/Object_Unit_Static_Extra_Health.h"
#include "../Object_Unit_Final/Object_Unit_Static_Genie_Bonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Restart_Point.h"
#include "../Object_Unit_Final/Object_Unit_Static_Spend_These.h"
#include "../Object_Unit_Final/Object_Unit_Static_Stick.h"

#include "../Object_Unit_Final/Object_Unit_Enemy_Assassin.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Circus.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Fat.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Pirates.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Straw.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Thin.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Camel.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Peddler.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Stall.h"

#include "../../Define.h"

#define Add_(type, name)					\
for (auto &b : oObjectStore->m##type##name) {	\
	Add(new Object_Unit_##type##name(*&b.first));	\
}

#define Add_Static(name)	Add_(Static_, name)
#define Add_Enemy(name)		Add_(Enemy_, name)
#define Add_NPC(name)		Add_(NPC_, name)

Scene_AgrabahMarket::Scene_AgrabahMarket() : Scene() {
	oObjectStore = new Scene_ObjectStore("AgrabahMarket_Block");

	//# Unit
	oPlayer = new Object_Unit_Aladdin();
	oMapBack = new Object_Map_AgrabahMarket_Back();
	oMapFront = new Object_Map_AgrabahMarket_Front();

	oMapBack->AfterAddToScene();
	oMapFront->AfterAddToScene();

	oObjectStore->mScene =
	oPlayer->mScene =
	oMapBack->mScene =
	oMapFront->mScene = this;

	//# Status
	
	oHealthMeter->mScene =
	oMagicLamp->mScene =
	oLife->mScene =
	oNLife->mScene =
	oSpendthese->mScene =
	oNspendthese->mScene =
	oScore_1->mScene =
	oScore_2->mScene =
	oScore_3->mScene =
	oScore_4->mScene =
	oSand_1->mScene =
	oSand_2->mScene =
	oSand_3->mScene =
	oSand_4->mScene =
	oSand_5->mScene =
	oCloud_1->mScene =
	oCloud_2->mScene =
	oCloud_3->mScene =
	oCloud_4->mScene =
	oApple->mScene =
	oN_Apple_u->mScene =
	oN_Apple_t->mScene = this;
}
