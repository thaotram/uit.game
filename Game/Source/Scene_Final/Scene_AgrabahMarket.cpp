	 #include "Scene_AgrabahMarket.h"


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
	Add(new Object_Status_Spendthese());
	Add(new Object_Status_Number_S(9));
}