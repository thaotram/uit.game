﻿#pragma once
#include <list>
#include "../GameDebug.h"
#include "../GameGlobal.h"
#include "../Object/Object.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Scene/Scene_Status.h"
#include "../Scene/Scene_Background.h"
#include "../Utility/Float_Easing.h"

using namespace std;

class Scene {
public:
    Scene();
    ~Scene();

    Vector mCamera;

    static Object*          oPlayer;
    static Scene_Status*    oStatus;
    Scene_Background*       oBackground;
    Scene_ObjectStore*      oObjectStore;
    Object*                 oMapBack;
    Object*                 oMapFront;

    //# Status Value
    int mBlood;
    int mApple;
    int mSpendthese;
    int mExtrahealth;
    Float_Easing mScore;

    void SceneRender(float delay);

    void OnKeyDown(int pKeyCode);
    void OnKeyUp(int pKeyCode);
    void OnMouseDown(float pX, float pY){};

    static void ReplaceScene(Scene* pScene);
    static Scene* mScene;
};