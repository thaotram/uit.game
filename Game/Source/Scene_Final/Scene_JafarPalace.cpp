#include "Scene_JafarPalace.h"

#include "../../Define.h"
#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Map_Final/Object_Map_JafarPalace_Background.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Jarfar.h"

Scene_JafarPalace::Scene_JafarPalace() : Scene() {
    oObjectStore = new Scene_ObjectStore("JafarPalace_Block");
    oStatus = new Scene_Status();
    oPlayer = new Object_Unit_Aladdin(90, 352);
    oBoss = new Object_Unit_Enemy_Jarfar(412, 340);
    oMapBackground = new Object_Screen("Screen", "JafarPalace_Background");
    oMapBack = new Object_Map_JafarPalace_Back();
    oMapBack->AfterAddToScene();

	((Object_Screen *)oTransparentScreen)->mAlpha = 0;
}

void Scene_JafarPalace::SceneRender(float delay) {
    //# Update
    Scene::mScore.Update(delay);
    
    oPlayer->ObjectUpdateEvent(delay);
    oObjectStore->ObjectUpdateEvent(delay);
	oBoss->ObjectUpdateEvent(delay);
    oMapBack->ObjectUpdateEvent(delay);
    oMapBackground->ObjectUpdateEvent(delay);
    oStatus->ObjectUpdateEvent(delay);
    oTransparentScreen->ObjectUpdateEvent(delay);

    //# Remove item in RemoveList
    oObjectStore->ObjectRemoveMarkedDelete();

    //# Render
    oMapBackground->ObjectRender(delay);
    oMapBack->ObjectRender(delay);
    oObjectStore->ObjectRender(delay);
	oBoss->ObjectRender(delay);
    oPlayer->ObjectRender(delay);
    oStatus->ObjectRender(delay);
    oTransparentScreen->ObjectRender(delay);
}
