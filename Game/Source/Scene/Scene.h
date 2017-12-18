#pragma once
#include <list>
#include "../GameGlobal.h"
#include "../GameDebug.h"
#include "../Scene/Scene_Camera.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../Utility/Float_Easing.h"
#include "../Object/Object.h"

using namespace std;

class Scene {
public:
	Scene();
	~Scene();

	Vector mCamera;

	//# Object
	Scene_ObjectStore * oObjectStore;
	Object * oPlayer;
	Object * oMapBack;
	Object * oMapFront;
	Object * oMagicLamp;
	Object * oHealthMeter;

	Object * oSpendthese;
	Object * oNspendthese;

	Object * oLife;
	Object * oNLife;

	Object * oApple;
	Object * oN_Apple_u;
	Object * oN_Apple_t;

	Object * oScore_1;
	Object * oScore_2;
	Object * oScore_3;
	Object * oScore_4;


	//# Status
	int mBlood;
	int mApple;
	int mSpendthese;
	int mExtrahealth;

	Float_Easing mScore;

	void SceneRender(float delay);

	void OnKeyDown(int pKeyCode);
	void OnKeyUp(int pKeyCode);
	void OnMouseDown(float pX, float pY) {};

	static void ReplaceScene(Scene * pScene);
	static Scene * mScene;
};