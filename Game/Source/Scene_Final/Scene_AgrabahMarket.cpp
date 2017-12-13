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

#define Add_Block(start, type, object)			\
if (b.first == BlockType::type)					\
Add(											\
	start, 										\
	new object(b.second.left, b.second.top)		\
);												\

void Scene_AgrabahMarket::AddBlock(int start)
{
	for (auto &b : *mMapBlock) {
		Add_Block(str, apple, Object_Unit_Static_Apple);
		Add_Block(str, black_magiclamp, Object_Unit_Static_Black_Magiclamp);
		Add_Block(str, geniebonus, Object_Unit_Static_Geniebonus);
		Add_Block(str, spendthese_item, Object_Unit_Static_Spendthese_Item);
		Add_Block(str, abubonus, Object_Unit_Static_Abubonus);
		Add_Block(str, extrahealth, Object_Unit_Static_Extrahealth);
		Add_Block(str, restartpoint, Object_Unit_Static_Restartpoint);
		i++;
	}
}

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mMapBlock = new Object_Map_Block("AgrabahMarket_Block");

	//# Map
	Add("1", new Object_Map_AgrabahMarket_Back());
	Add("8", new Object_Map_AgrabahMarket_Front());
	
	//# Static Item
	AddBlock("4");

	//# Unit
	Add("5", new Object_Unit_Aladdin());
	Add(1, new Object_Map_AgrabahMarket_Back());
	Add(10000, new Object_Map_AgrabahMarket_Front());

	//# Block 
	AddBlock(4000);
	
	//# Unit
	Add(5000, new Object_Unit_Aladdin());
	
	//# Status
	Add(9000, new Object_Status_Apple());
}