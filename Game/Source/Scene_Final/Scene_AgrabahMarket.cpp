#include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Map_Block/Object_Map_Block.h"

#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Static_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Black_Magiclamp.h"
#include "../Object_Unit_Final/Object_Unit_Geniebonus.h"
#include "../Object_Unit_Final/Object_Unit_Spendthese_Item.h"

#include "../Object_Status_Final/Object_Status_Apple.h"

#include "../../Define.h"

#define Add_Block(string, type, object)											\
if (b.first == BlockType::type) {												\
	Add(string + #type + toString(int(i)), new object(b.second.left, b.second.top));	\
}																				\

string toString(int number,int l=3) {
	string out = to_string(number);
	for (int i = out.length(); i < l; i++) {
		out = "0" + out;
	}
	return out;
}

void Scene_AgrabahMarket::AddBlock(string str)
{
	int i = 0;
	for (auto &b : *mMapBlock) {
		Add_Block(str, apple, Object_Unit_Static_Apple);
		Add_Block(str, black_magiclamp, Object_Unit_Black_Magiclamp);
		Add_Block(str, geniebonus, Object_Unit_Geniebonus);
		Add_Block(str, spendthese_item, Object_Unit_Spendthese_Item);
		i++;																\
	}
}

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mMapBlock = new Object_Map_Block("AgrabahMarket_Block");
	// Add Object
	Add("1", new Object_Map_AgrabahMarket_Back());
	Add("5", new Object_Unit_Aladdin());
	// AddBlock("2");
	Add("8", new Object_Status_Apple());
	//Add("8", new Object_Map_AgrabahMarket_Front());
}