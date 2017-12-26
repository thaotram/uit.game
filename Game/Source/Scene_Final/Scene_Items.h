#pragma once
#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Object_Map_Final/Object_Map_Items_Front.h"
#include "../Scene_Final/Scene_AgrabahMarket.h"


#include "../../Define.h"

using namespace std;

class Scene_Items final : public Scene {
private:
	Object* oMapBackground;
	Object* oMapBack;
	Scene_Items* oStatus;

public:
	Scene_Items();
	~Scene_Items() {};

	Object* oBoss;
	void SceneRender(float delay);
};