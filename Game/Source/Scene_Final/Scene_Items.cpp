#include "Scene_Items.h"

#include "../../Define.h"
#include "../Object_Screen/Object_Screen.h"

#define I GameGlobal::Input
#define Z I[CHAR_Z]
#define X I[CHAR_X]
#define C I[CHAR_C]
#define alpha oTransparentScreen->mAlpha

Scene_Items::Scene_Items() : Scene() {
	delete mBackScene;
	oObjectStore = new Scene_ObjectStore("");
	oBackground = new Object_Screen("Item", "background_item");
	oItem = new Object_Screen("Item", "guide");
	alpha = 0;
	isNext = false;
	// mSound = new GameSound(L"Sound/OST/03_Prince Ali.wav");
}

void Scene_Items::SceneRender(float delay) {
	if ((Z || X || C) && !isNext) {
		Z = X = C = false;
		isNext = true;
		Scene::NextScene(new Scene_AgrabahMarket());
	}

	oBackground->ObjectUpdateEvent(delay);
	oItem->ObjectUpdateEvent(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);

	oBackground->ObjectRender(delay);
	oItem->ObjectRender(delay);
	oTransparentScreen->ObjectRender(delay);
}
