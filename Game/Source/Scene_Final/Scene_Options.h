#pragma once
#include "../Scene/Scene.h"
#include "../Scene/Scene_Status.h"
#include "../Scene/Scene_ObjectStore.h"

using namespace std;

class Scene_Options final:public Scene
{
private:
	Scene* pLastScene;
	float mTimer;
	Object* oMapBackground;
	Scene_Status* oStatus;
public:
	Scene_Options();
	~Scene_Options();
	void SceneRender(float delay);
};

