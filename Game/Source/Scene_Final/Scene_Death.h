#pragma once
#include "../Scene/Scene.h"

using namespace std;

class Scene_Death final : public Scene {
private: 
// oAbu = 
public:
    Scene_Death();
    ~Scene_Death() {};
    void SceneRender(float delay);
};