#include "Scene_Death.h"

#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

Scene_Death::Scene_Death() : Scene() {
    oObjectStore = new Scene_ObjectStore("");
    oPlayer = new Object_Unit_Aladdin(200, 200);
    oPlayer->GetAnimation()->Set("die", 1);
}

void Scene_Death::SceneRender(float delay) {
    oPlayer->ObjectUpdateEvent(delay);
    oPlayer->ObjectRender(delay);
}