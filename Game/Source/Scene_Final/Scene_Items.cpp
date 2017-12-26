#include "Scene_Items.h"

#include "../../Define.h"
#include "../Object_Map_Final/Object_Map_Items_Front.h"
#include "../Object_Screen/Object_Screen.h"

#define I GameGlobal::Input
#define Z I[CHAR_Z]
#define X I[CHAR_X]
#define C I[CHAR_C]

Scene_Items::Scene_Items() : Scene() {
	oObjectStore = new Scene_ObjectStore("");
	oMapBackground = new Object_Screen("Item", "background_item");
	oMapBack = new Object_Map_Items_Front();
	oMapBack->AfterAddToScene();
}

void Scene_Items::SceneRender(float delay) {
	if (Z || X || C) {
		Scene::NextScene(new Scene_AgrabahMarket());
	}

	oMapBack->ObjectUpdateEvent(delay);
	oMapBackground->ObjectUpdateEvent(delay);
	oMapBack->ObjectRender(delay);
}
