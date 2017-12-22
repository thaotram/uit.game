#include "Scene_Death.h"

#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

Scene_Death::Scene_Death() : Scene() {
    oObjectStore = new Scene_ObjectStore("");
    oPlayer = new Object_Unit_Aladdin(160, 150);
    oPlayer->GetAnimation()->Set("die", 1);
	oAbu = new Object_Unit_NPC_Abu(160+90, 150+19);
}

Scene_Death::~Scene_Death()
{
	delete oAbu;
	delete oPlayer;
}

void Scene_Death::SceneRender(float delay) {
    oPlayer->ObjectUpdateEvent(delay);
	oAbu->ObjectUpdateEvent(delay);

    oPlayer->ObjectRender(delay);
	oAbu->ObjectRender(delay);
}