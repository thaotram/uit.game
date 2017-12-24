#include "Scene_JafarPalace.h"

#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Map_Final/Object_Map_JafarPalace_Background.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../../Define.h"

Scene_JafarPalace::Scene_JafarPalace() : Scene() {
	oObjectStore = new Scene_ObjectStore("JafarPalace_Block");
	oPlayer = new Object_Unit_Aladdin(200, 50);

	oMapBackground = new Object_Screen("Screen", "JafarPalace_Background");
	oMapBack = new Object_Map_JafarPalace_Back();
	oMapBack->AfterAddToScene();

	((Object_Screen *)oTransparentScreen)->mAlpha = 255;
}

void Scene_JafarPalace::SceneRender(float delay){
    //# Update
	oPlayer->ObjectUpdateEvent(delay);
	oObjectStore->ObjectUpdateEvent(delay);
	oMapBack->ObjectUpdateEvent(delay);
	oMapBackground->ObjectUpdateEvent(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);

	//# Remove item in RemoveList
	oObjectStore->ObjectRemoveMarkedDelete();

    //# Render
	oMapBackground->ObjectRender(delay);
	oMapBack->ObjectRender(delay);
	oObjectStore->ObjectRender(delay);
    oPlayer->ObjectRender(delay);
    oTransparentScreen->ObjectRender(delay);
}
