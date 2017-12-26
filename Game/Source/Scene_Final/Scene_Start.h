#pragma once
#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../../Define.h"

using namespace std;

class Scene_Start final :public Scene
{
private:
	Object* oMapBackground;
	//Scene* pLastScene;
	//float mTimer;
public:
	Scene_Start();
	~Scene_Start() {};
	void SceneRender(float delay);
	//void ObjectIntersect(Object * pObject);
};

