#pragma once
#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

using namespace std;

class Scene_Win final : public Scene {
private:
	Object* oMapBackground;
	//Object* oMapBack;
	//Scene_Win* oStatus;

public:
	Scene_Win();
	~Scene_Win() {};

	//Object* oBoss;
	void SceneRender(float delay);
};