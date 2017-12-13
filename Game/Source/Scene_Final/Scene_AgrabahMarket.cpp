#include "Scene_AgrabahMarket.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Map_Block/Object_Map_Block.h"

#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Static_Apple.h"

#include "../../Define.h"

string toString(int number,int l=3) {
	string out = to_string(number);
	for (int i = out.length(); i < l; i++) {
		out = "0" + out;
	}
	return out;
}

Scene_AgrabahMarket::Scene_AgrabahMarket() {
	mMapBlock = new Object_Map_Block("AgrabahMarket_Block");

	// Add Object
	Add("1", new Object_Map_AgrabahMarket_Back());
	Add("5", new Object_Unit_Aladdin());
	Add("9", new Object_Map_AgrabahMarket_Front());

	int i = 0;
	for(auto &b: *mMapBlock){
		if (b.first == BlockType::apple) {
			Add("2"+toString(i), new Object_Unit_Static_Apple(b.second.left, b.second.top));
			i++;
		}
	}

}