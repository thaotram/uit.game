#include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Map_Block/Object_Map_Block.h"

#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Static_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Static_Black_Magiclamp.h"
#include "../Object_Unit_Final/Object_Unit_Static_Geniebonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Spendthese_Item.h"
#include "../Object_Unit_Final/Object_Unit_Static_Abubonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Extrahealth.h"
#include "../Object_Unit_Final/Object_Unit_Static_Restartpoint.h"

#include "../Object_Status_Final/Object_Status_Apple.h"

#include "../../Define.h"

#define Add_Block(index, type)					\
for(auto &b : mMapBlock->m##type) {				\
	Add(index, new Object_Unit_Static_##type(	\
			(float)b.left,						\
			(float)b.top						\
		)										\
	);											\
	index++;									\
}												

#define a(v) mMapBlock->m##v
void Scene_AgrabahMarket::AddBlock(int start) {
}

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mMapBlock = new Object_Map_Block("AgrabahMarket_Block");

	//# Map
	Add(1, new Object_Map_AgrabahMarket_Back());
	Add(5000, new Object_Map_AgrabahMarket_Front());

	//# Block
	int index = 4000;
	Add_Block(index, Apple);

	//# Unit
	Add(2, new Object_Unit_Aladdin());

	//# Status
	//Add(1200, new Object_Status_Apple());
}