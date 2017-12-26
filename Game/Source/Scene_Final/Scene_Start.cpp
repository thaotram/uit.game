#include "Scene_Start.h"

#include "../../Define.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Scene_Final/Scene_AgrabahMarket.h"

#define I GameGlobal::Input
#define Z I[CHAR_Z]
#define X I[CHAR_X]
#define C I[CHAR_C]

Scene_Start::Scene_Start() : Scene()
{

	oObjectStore = new Scene_ObjectStore("");
	oMapBackground = new Object_Screen("Option_Scene", "main_menu");
}

void Scene_Start::SceneRender(float delay)
{
	if (Z || X || C){
		Scene::NextScene(new Scene_AgrabahMarket());
	}
	oMapBackground->ObjectUpdateEvent(delay);
	oMapBackground->ObjectRender(delay);
}