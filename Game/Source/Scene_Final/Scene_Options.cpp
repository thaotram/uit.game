#include "Scene_Options.h"

#include "../Object_Screen/Object_Screen.h"
#include "../../Define.h"

Scene_Options::Scene_Options() : Scene()
{
	oObjectStore = new Scene_ObjectStore("");
	mTimer = 0;
}

Scene_Options::~Scene_Options()
{
}

//void Scene_Options::SceneRender(float delay)
//{
//}