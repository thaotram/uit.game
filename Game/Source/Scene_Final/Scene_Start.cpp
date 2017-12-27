#include "Scene_Start.h"

#include "../../Define.h"
#include "../Object_Screen/Object_Screen.h"

#define I GameGlobal::Input
#define Z I[CHAR_Z]
#define X I[CHAR_X]
#define C I[CHAR_C]
#define alpha oTransparentScreen->mAlpha

Scene_Start::Scene_Start() : Scene(){
	delete mBackScene;
	oObjectStore = new Scene_ObjectStore("");
	oMapBackground = new Object_Screen("Option_Scene", "main_menu");
	alpha = 0;
	isNext = false;

	Scene::mBlood = 7;
	Scene::mApple = 10;
	Scene::mSpendthese = 0;
	Scene::mExtrahealth = 3;
	Scene::mScore << 0;
}

void Scene_Start::SceneRender(float delay)
{
	if ((Z || X || C) && !isNext) {
		isNext = true;
		Z = X = C = false;
		Scene::NextScene(new Scene_Items());
	}
	oMapBackground->ObjectUpdateEvent(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);

	oMapBackground->ObjectRender(delay);
	oTransparentScreen->ObjectRender(delay);
}