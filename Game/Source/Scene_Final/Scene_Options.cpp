#include "Scene_Options.h"

#include "../Object_Screen/Object_Screen.h"
#include "../../Define.h"

Scene_Options::Scene_Options() : Scene()
{
	oObjectStore = new Scene_ObjectStore("");
	oStatus = new Scene_Status();
	oMapBackground = new Object_Screen("Screen", "JafarPalace_Background");

	mTimer = 0;
}

Scene_Options::~Scene_Options()
{

}

//void Scene_Options::SceneRender(float delay)
//{
//}