#include "Scene_Start.h"

#include "../../Define.h"
#include "../Object_Map_Final/Object_Map_Scene_Start.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Scene_Final/Scene_AgrabahMarket.h"

#define I GameGlobal::Input
#define E I[ENTER]

Scene_Start::Scene_Start() : Scene()
{
	oObjectStore = new Scene_ObjectStore("");
	oMapBackground = new Object_Screen("Option_Scene", "main_menu");
}

void Scene_Start::SceneRender(float delay)
{
	oMapBackground->ObjectUpdateEvent(delay);
	oMapBackground->ObjectRender(delay);
}