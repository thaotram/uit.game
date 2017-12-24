#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <math.h>
#include <vector>

#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Scene/Scene_Status.h"
#include "../Object/Object_List.h"

#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"

#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

using namespace std;

class Scene_AgrabahMarket final : public Scene {
private:
    Scene_Status* oStatus;
    Object_List* oBackground;
    Object* oMapBack;
    Object* oMapFront;

public:
    Scene_AgrabahMarket();
    ~Scene_AgrabahMarket(){};
    void SceneRender(float pDelay);
};
