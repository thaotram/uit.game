#pragma once
#include "../Object_Unit_Final/Object_Unit_NPC_Abu.h"
#include "../Scene/Scene.h"

using namespace std;

class Scene_Death final : public Scene {
private:
    Object* oAbu;
    Scene* pLastScene;
	float mTimer;
public:
    Scene_Death();
    ~Scene_Death();
    void SceneRender(float delay);
};