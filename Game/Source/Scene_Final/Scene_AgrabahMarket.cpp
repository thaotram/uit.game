#include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Map_Block/Object_Map_Block.h"

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

#include "../Object_Unit_Final/Object_Unit_Enemy_Assassin.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Circus.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Fat.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Pirates.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Straw.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Thin.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Camel.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Peddler.h"

#include "../../Define.h"

#define Add_(type, name)					\
for (auto &b : mMapBlock->m##type##name) {	\
	Add(new Object_Unit_##type##name(*&b));	\
}

#define Add_Static(name)	Add_(Static_, name)
#define Add_Enemy(name)		Add_(Enemy_, name)
#define Add_NPC(name)		Add_(NPC_, name)

Scene_AgrabahMarket::Scene_AgrabahMarket() : Scene() {
	mMapBlock = new Object_Map_Block("AgrabahMarket_Block");

	//# Map
	Add(new Object_Map_AgrabahMarket_Back());

	//# Block

	Add_Static(Abubonus);
	Add_Static(Apple);
	Add_Static(Black_Magic_Lamp);
	Add_Static(Block_Drop);
	Add_Static(Extra_Health);
	Add_Static(Genie_Bonus);
	Add_Static(Restart_Point);
	Add_Static(Spend_These);
	Add_Static(Stick);

	//# NPC
	Add_NPC(Camel);
	Add_NPC(Peddler);
	
	//# Enemy
	Add_Enemy(Assassin);
	Add_Enemy(Circus);
	Add_Enemy(Fat);
	Add_Enemy(Pirates);
	Add_Enemy(Straw);
	Add_Enemy(Thin);

	//# Unit
	Add(new Object_Unit_Aladdin(), itPlayer);
	Add(new Object_Map_AgrabahMarket_Front(), itMapFront);

	//# Status
	/// Phần này để cho Huyền làm
	// Add(new Object_Status_Apple());
	// Add(new Object_Status_Magic_Lamp());
	// Add(new Object_Status_Health_Meter(mBlood));
}