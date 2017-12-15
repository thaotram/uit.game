	 #include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Map_Block/Object_Map_Block.h"

#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../Object_Unit_Final/Object_Unit_Static_Abubonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Static_Black_Magic_Lamp.h"
#include "../Object_Unit_Final/Object_Unit_Static_Block_Drop.h"
#include "../Object_Unit_Final/Object_Unit_Static_Extra_Health.h"
#include "../Object_Unit_Final/Object_Unit_Static_Genie_Bonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Restart_Point.h"
#include "../Object_Unit_Final/Object_Unit_Static_Spend_These.h"

#include "../Object_Status_Final/Object_Status_Apple.h"
#include "../Object_Status_Final/Object_Status_Life.h"
#include "../Object_Status_Final/Object_Status_Health_Meter.h"
#include "../Object_Status_Final/Object_Status_Magic_Lamp.h"

#include "../../Define.h"

#define Add_Static(name)				\
for(auto &b : mMapBlock->m##name) {		\
	Add(new Object_Unit_Static_##name(	\
		(float)b.left,					\
		(float)b.top					\
	));									\
}

Scene_AgrabahMarket::Scene_AgrabahMarket() {
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

	//# Unit
	Add(new Object_Unit_Aladdin());
	Add(new Object_Map_AgrabahMarket_Front());

	//# Status
	Add(new Object_Status_Apple());
	Add(new Object_Status_Magic_Lamp());
	Add(new Object_Status_Health_Meter(1));
}