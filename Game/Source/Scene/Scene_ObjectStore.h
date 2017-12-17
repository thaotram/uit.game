#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <json.hpp>

#define V2 D3DXVECTOR2
using json = nlohmann::json;
using namespace std;

enum StairsState {
	Bot,
	Mid,
	Top
};

class Object;
class Scene;

class Scene_ObjectStore {
private:
	list<Object *> mRemoveList;

	list<RECT> mRope;
	list<RECT> mBar;
	list<RECT> mSquare;
	list<RECT> mStairs_slash;
	list<RECT> mStairs_backslash;
			   
	list<RECT> m_Stairs_slash;
	list<RECT> m_Square;
	list<RECT> m_Stairs_backslash;

	StairsState mStairsState;
	StairsState mStairsStateOld;
public:
	Scene_ObjectStore(string pName);
	~Scene_ObjectStore() {};

	Scene * mScene;

	//# Static Item
	list<pair<RECT, Object *>>	mStatic_Abubonus;
	list<pair<RECT, Object *>>	mStatic_Apple;
	list<pair<RECT, Object *>>	mStatic_Black_Magic_Lamp;
	list<pair<RECT, Object *>>	mStatic_Block_Drop;
	list<pair<RECT, Object *>>	mStatic_Extra_Health;
	list<pair<RECT, Object *>>	mStatic_Genie_Bonus;
	list<pair<RECT, Object *>>	mStatic_Restart_Point;
	list<pair<RECT, Object *>>	mStatic_Spend_These;
	list<pair<RECT, Object *>>	mStatic_Stick;

	//# NPC
	list<pair<RECT, Object *>>	mNPC_Camel;
	list<pair<RECT, Object *>>	mNPC_Peddler;

	//# Enemy
	list<pair<RECT, Object *>>	mEnemy_Assassin;
	list<pair<RECT, Object *>>	mEnemy_Circus;
	list<pair<RECT, Object *>>	mEnemy_Fat;
	list<pair<RECT, Object *>>	mEnemy_Pirates;
	list<pair<RECT, Object *>>	mEnemy_Straw;
	list<pair<RECT, Object *>>	mEnemy_Thin;

	void				ObjectUpdateEvent(float dt);
	void				ObjectRender(float dt);
	void				AddToRemoveList(Object * pObject);
	void				RemoveObjectMarkedDelete();

	void 				ObjectCheckCollision(Object * pObject);

	RECT				GetDistance(RECT u, Object * pUnit);
	void				UpdateStairState(RECT u);
	pair<bool, RECT>	GetRope(RECT u, float step);
	pair<bool, RECT>	GetBar(RECT u, float step);
	pair<bool, RECT> 	GetStick(RECT u, float step);
};