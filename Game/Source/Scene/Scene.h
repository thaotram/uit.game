#pragma once
#include <list>
#include "../GameDebug.h"
#include "../GameGlobal.h"
#include "../Object/Object.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Scene/Scene_Status.h"
#include "../Utility/Float_Easing.h"

using namespace std;

class Scene {
public:
    Scene();
    ~Scene();

    Vector mCamera;

    //# Object
    Scene_ObjectStore* oObjectStore;

    Object* oPlayer;
    Object* oMapBack;
    Object* oMapFront;

    //# Status
    Scene_Status* oStatus;

    // Object * oMagicLamp;
    // Object * oHealthMeter;

    // Object * oSpendthese;
    // Object * oNspendthese;

    // Object * oLife;
    // Object * oNLife;

    // Object * oApple;
    // Object * oN_Apple_u;
    // Object * oN_Apple_t;

    // Object * oScore_1;
    // Object * oScore_2;
    // Object * oScore_3;
    // Object * oScore_4;

    // Object* oSand_1;
    // Object* oSand_2;
    // Object* oSand_3;
    // Object* oSand_4;
    // Object* oSand_5;
    // Object* oCloud_1;
    // Object* oCloud_2;
    // Object* oCloud_3;
    // Object* oCloud_4;

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