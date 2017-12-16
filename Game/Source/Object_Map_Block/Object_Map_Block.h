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

class Object_Map_Block {
private:
	list<RECT>			mRope;
	list<RECT>			mBar;
	list<RECT>			mSquare;
	list<RECT>			mStairs_slash;
	list<RECT>			mStairs_backslash;

	list<RECT>			m_Stairs_slash;
	list<RECT>			m_Square;
	list<RECT>			m_Stairs_backslash;

	StairsState			mStairsState;
	StairsState			mStairsStateOld;
public:
	Object_Map_Block(string pName);
	~Object_Map_Block() {};

	//# Static Item
	list<RECT> mStatic_Abubonus;
	list<RECT> mStatic_Apple;
	list<RECT> mStatic_Black_Magic_Lamp;
	list<RECT> mStatic_Block_Drop;
	list<RECT> mStatic_Extra_Health;
	list<RECT> mStatic_Genie_Bonus;
	list<RECT> mStatic_Restart_Point;
	list<RECT> mStatic_Spend_These;
	list<RECT> mStatic_Stick;

	//# NPC
	list<RECT> 			mNPC_Camel;
	list<RECT> 			mNPC_Peddler;

	//# Enemy
	list<RECT> 			mEnemy_Assassin;
	list<RECT> 			mEnemy_Circus;
	list<RECT> 			mEnemy_Fat;
	list<RECT> 			mEnemy_Pirates;
	list<RECT> 			mEnemy_Straw;
	list<RECT> 			mEnemy_Thin;

	RECT				GetDistance(RECT u, Object * pUnit);
	void				UpdateStairState(RECT u);
	pair<bool, RECT>	GetRope(RECT u, float step);
	pair<bool, RECT>	GetBar(RECT u, float step);
};