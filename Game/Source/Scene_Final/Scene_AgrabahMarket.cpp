#include "Scene_AgrabahMarket.h"

#include "../../Define.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Status_Final/Object_Status_Cloud.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

Scene_AgrabahMarket::Scene_AgrabahMarket() : Scene() {
    const vector<State_Cloud> Vector_State_Cloud = 
		{Cloud1, Cloud2, Cloud3, Cloud4, Sand1, Sand2, Sand3, Sand4, Sand5};
	for (const auto &v : Vector_State_Cloud) {
		oBackground->push_back(new Object_Status_Cloud(v));
	}
    oObjectStore = new Scene_ObjectStore("AgrabahMarket_Block");
    oPlayer = new Object_Unit_Aladdin(50, 50);
    oMapBack = new Object_Map_AgrabahMarket_Back();
    oMapFront = new Object_Map_AgrabahMarket_Front();

    oMapBack->AfterAddToScene();
    oMapFront->AfterAddToScene();
}