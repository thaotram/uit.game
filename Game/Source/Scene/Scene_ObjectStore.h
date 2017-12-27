
#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <fstream>
#include <list>
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
	list<RECT> mRope;
	list<RECT> mBar;
	list<RECT> mSquare;
	list<RECT> mHorizontal;
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
	list<pair<RECT, Object *>>	mStatic_Fire;

	//# NPC
	list<pair<RECT, Object *>>	mNPC_Camel;
	list<pair<RECT, Object *>>	mNPC_Stall;
	list<pair<RECT, Object *>>	mNPC_Peddler;

	//# Enemy
	list<pair<RECT, Object *>>	mEnemy_Assassin;
	list<pair<RECT, Object *>>	mEnemy_Circus;
	list<pair<RECT, Object *>>	mEnemy_Fat;
	list<pair<RECT, Object *>>	mEnemy_Pirates;
	list<pair<RECT, Object *>>	mEnemy_Straw;
	list<pair<RECT, Object *>>	mEnemy_Thin;

	//# Lost
	list<Object*>				mLost;

	void				ObjectUpdateEvent(float dt);
	void				ObjectRender(float dt);
	void				ObjectRemoveMarkedDelete();

	void 				Collision_Player_Enemy(Object * pPlayer);
	void 				Collision_Player_Enemy_Each(Object * pPlayer, list<pair<RECT, Object *>> * pListEnemy);
	void 				Collision_Player_Static(Object * pPlayer);
	void 				Collision_Player_Static_Each(Object * pPlayer, list<pair<RECT, Object *>> * pListStatic);
	void 				Collision_Enemy_Player(Object * pEnemy);
	void 				Collision_BulletStar_Player(Object * pBulletStar);
	void 				Collision_Apple_Jarfar(Object * pApple);
	void				Collision_Player_Knife(Object * pObject);

	RECT				GetDistance(RECT u, Object * pUnit);
	void				UpdateStairState(RECT u);

	pair<bool, RECT>	GetBar(RECT u, float step);
	pair<bool, RECT>	GetRope(RECT u, float step);
	pair<bool, pair<RECT, Object *> *> GetStick(RECT u, float step);
	pair<bool, pair<RECT, Object *> *> GetCamel(RECT u, float step);
};