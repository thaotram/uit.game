#pragma once
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
private:
    static float mTime;
    static float mDelay;
public:
    Scene();
    ~Scene();

    Vector mCamera;

    Object*                 oPlayer;
    Scene_Status*           oStatus;
    Scene_Background*       oBackground;
    Scene_ObjectStore*      oObjectStore;
    Object*                 oMapBack;
    Object*                 oMapFront;

    //# Status Value
    static int mBlood;
	static int mApple;
	static int mSpendthese;
	static int mExtrahealth;
	static Float_Easing mScore;

    virtual void SceneRender(float pDelay);

    void OnKeyDown(int pKeyCode);
    void OnKeyUp(int pKeyCode);
    void OnMouseDown(float pX, float pY){};

    static void ReplaceScene(Scene* pScene);
    static void ReplaceScene(Scene* pScene, float delay);
    static Scene* mScene;
    static Scene* mNextScene;
};