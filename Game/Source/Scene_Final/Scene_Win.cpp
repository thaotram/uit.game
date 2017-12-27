#include "Scene_Win.h"

#include "../../Define.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

Scene_Win::Scene_Win() : Scene() {
	oObjectStore = new Scene_ObjectStore("");
	oPlayer = new Object_Unit_Aladdin(90, 352);
	
	oMapBackground = new Object_Screen("End", "Aladdin_Miscellaneous_Cutscenes");
	//oMapBack = new Object_Map_JafarPalace_Back();
	//oMapBack->AfterAddToScene();

	((Object_Screen *)oTransparentScreen)->mAlpha = 0;
}

void Scene_Win::SceneRender(float delay) {
	//# Update
	oPlayer->ObjectUpdateEvent(delay);
	//oObjectStore->ObjectUpdateEvent(delay);
	//oBoss->ObjectUpdateEvent(delay);
	//oMapBack->ObjectUpdateEvent(delay);
	oMapBackground->ObjectUpdateEvent(delay);
	//oStatus->ObjectUpdateEvent(delay);
	//oTransparentScreen->ObjectUpdateEvent(delay);

	//# Remove item in RemoveList
	//oObjectStore->ObjectRemoveMarkedDelete();

	//# Render
	oMapBackground->ObjectRender(delay);
	//oMapBack->ObjectRender(delay);
	//oBoss->ObjectRender(delay);
	//oObjectStore->ObjectRender(delay);
	oPlayer->ObjectRender(delay);
	//oStatus->ObjectRender(delay);
	oTransparentScreen->ObjectRender(delay);
}
