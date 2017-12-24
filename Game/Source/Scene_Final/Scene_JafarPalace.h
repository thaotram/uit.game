#pragma once
#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_Status.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"

#include "../../Define.h"

using namespace std;

class Scene_JafarPalace final : public Scene {
private: 
	Object* oMapBackground;
	Object* oMapBack;
	Object* oBoss;
    Scene_Status* oStatus;

public:
	Scene_JafarPalace();
	~Scene_JafarPalace() {};
	void SceneRender(float delay);
};