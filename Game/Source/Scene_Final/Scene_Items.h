#pragma once
#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Scene_Final/Scene_AgrabahMarket.h"

#include "../../Define.h"

using namespace std;

class Scene_Items final : public Scene {
private:
	Object* oBackground;
	Object* oItem;
	Scene_Items* oStatus;
	bool isNext;

public:
	Scene_Items();
	~Scene_Items() {};

	Object* oBoss;
	void SceneRender(float delay);
};