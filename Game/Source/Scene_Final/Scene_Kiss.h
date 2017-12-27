#pragma once
#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

using namespace std;

class Scene_Kiss final : public Scene {
public:
	Scene_Kiss();
	~Scene_Kiss() {};

	//Object* oBoss;
	void SceneRender(float delay);
};