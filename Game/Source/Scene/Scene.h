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

	//list<Object *>::iterator Add(Object * pObject);
	//list<Object *>::iterator Add(list<Object *>::iterator pIt, Object * pObject);
	//void Add(Object * pObject, list<Object *>::iterator &pItOut);
	//void Add(list<Object *>::iterator pIt, Object * pObject, list<Object *>::iterator &pItOut);

	static void ReplaceScene(Scene * pScene);
	static Scene * mScene;
};