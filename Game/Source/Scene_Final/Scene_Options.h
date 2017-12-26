#pragma once
#include "../Scene/Scene.h"

using namespace std;

class Scene_Options final:public Scene
{
private:
	Scene* pLastScene;
	float mTimer;
public:
	Scene_Options();
	~Scene_Options();
	//void SceneRender(float delay);
};

