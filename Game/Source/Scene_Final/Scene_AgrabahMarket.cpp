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

#include "../Object_Status_Final/Object_Status_Apple.h"
#include "../Object_Status_Final/Object_Status_Life.h"
#include "../Object_Status_Final/Object_Status_Health_Meter.h"
#include "../Object_Status_Final/Object_Status_Magic_Lamp.h"
#include "../Object_Status_Final/Object_Status_Number_S.h"
#include "../Object_Status_Final/Object_Status_Number_L.h"
#include "../Object_Status_Final/Object_Status_Spendthese.h"
#include "../Object_Status_Final/Object_Status_Cloud.h"

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
	oApple = new Object_Status_Apple();
	oN_Apple_u = new Object_Status_Number_S(296, 200, S_Apple_Ones);
	oN_Apple_t = new Object_Status_Number_S(288, 200, S_Apple_Tens);

	oSpendthese = new Object_Status_Spendthese();
	oNspendthese = new Object_Status_Number_S(253, 200, S_Spendthese);

	oLife = new Object_Status_Life();
	oNLife = new Object_Status_Number_S(42, 200, S_Life);

	oMagicLamp = new Object_Status_Magic_Lamp();
	oHealthMeter = new Object_Status_Health_Meter();

	oScore_1 = new Object_Status_Number_L(275, 20, L_Score_Ones);
	oScore_2 = new Object_Status_Number_L(258, 20, L_Score_Tens);
	oScore_3 = new Object_Status_Number_L(241, 20, L_Score_Hundreds);
	oScore_4 = new Object_Status_Number_L(224, 20, L_Score_Thousand);

	oSand_1 = new Object_Status_Cloud(Sand1);
	oSand_2 = new Object_Status_Cloud(Sand2);
	oSand_3 = new Object_Status_Cloud(Sand3);
	oSand_4 = new Object_Status_Cloud(Sand4);
	oSand_5 = new Object_Status_Cloud(Sand5);
	oCloud_1 = new Object_Status_Cloud(Cloud1);
	oCloud_2 = new Object_Status_Cloud(Cloud2);
	oCloud_3 = new Object_Status_Cloud(Cloud3);
	oCloud_4 = new Object_Status_Cloud(Cloud4);
	
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
