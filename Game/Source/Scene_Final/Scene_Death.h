#pragma once
#include "../Scene/Scene.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Abu.h"

using namespace std;

class Scene_Death final : public Scene {
private: 
	Object* oAbu;
public:
    Scene_Death();
    ~Scene_Death();
    void SceneRender(float delay);
};