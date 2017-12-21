#include "Scene_AgrabahMarket.h"

#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Status_Final/Object_Status_Cloud.h"
#include "../../Define.h"

Scene_AgrabahMarket::Scene_AgrabahMarket() : Scene() {
	*oBackground << new Object_Status_Cloud(Cloud1);
	*oBackground << new Object_Status_Cloud(Cloud2);
	*oBackground << new Object_Status_Cloud(Cloud3);
	*oBackground << new Object_Status_Cloud(Cloud4);
	*oBackground << new Object_Status_Cloud(Sand1);
	*oBackground << new Object_Status_Cloud(Sand2);
	*oBackground << new Object_Status_Cloud(Sand3);
	*oBackground << new Object_Status_Cloud(Sand4);
	*oBackground << new Object_Status_Cloud(Sand5);
    
    oObjectStore = new Scene_ObjectStore("AgrabahMarket_Block");
    oPlayer = new Object_Unit_Aladdin(50,50);
    oMapBack = new Object_Map_AgrabahMarket_Back();
    oMapFront = new Object_Map_AgrabahMarket_Front();

    oMapBack->AfterAddToScene();
    oMapFront->AfterAddToScene();
}
