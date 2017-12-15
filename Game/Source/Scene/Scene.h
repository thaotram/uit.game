#pragma once
#include <list>
#include "../GameGlobal.h"
#include "../GameDebug.h"
#include "../Scene/Scene_Camera.h"
#include "../Object_Map_Block/Object_Map_Block.h"

using namespace std;
class Object;

class Scene : public list<Object *> {
private:
	static Scene *	mCurrentScene;
	list<Object *>	mRemoveList;
public:
	Scene();
	~Scene();

	Vector mCamera;
	Object_Map_Block * mMapBlock;

	int mBlood;
	int mApple;
	int mSpendthese;
	int mExtrahealth;
	int mScore;

	list<Object *>::iterator itPlayer;
	list<Object *>::iterator itMapBack;
	list<Object *>::iterator itMapFront;

	void SceneRender(float delay);

	void OnKeyDown(int pKeyCode);
	void OnKeyUp(int pKeyCode);
	void OnMouseDown(float pX, float pY) {};

	list<Object *>::iterator Add(Object * pObject);
	list<Object *>::iterator Add(list<Object *>::iterator pIt, Object * pObject);
	void Add(Object * pObject, list<Object *>::iterator &pItOut);
	void Add(list<Object *>::iterator pIt, Object * pObject, list<Object *>::iterator &pItOut);
	
	void AddToRemoveList(Object * pIt);

	static void ReplaceScene(Scene * pScene);
	static Scene * GetCurrentScene();
};