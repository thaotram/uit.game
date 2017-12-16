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

	list<RECT> 			mNPC_Camel;
	list<RECT> 			mNPC_Peddler;
	list<RECT> 			mEnemy_Assassin;
	list<RECT> 			mEnemy_Circus;
	list<RECT> 			mEnemy_Fat;
	list<RECT> 			mEnemy_Pirates;
	list<RECT> 			mEnemy_Straw;
	list<RECT> 			mEnemy_Thin;

	StairsState			mStairsState;
	StairsState			mStairsStateOld;
public:
	Object_Map_Block(string pName);
	~Object_Map_Block() {};

	//# Static Item
	list<RECT> mAbubonus;
	list<RECT> mApple;
	list<RECT> mBlack_Magic_Lamp;
	list<RECT> mBlock_Drop;
	list<RECT> mExtra_Health;
	list<RECT> mGenie_Bonus;
	list<RECT> mRestart_Point;
	list<RECT> mSpend_These;

	RECT				GetDistance(RECT u, Object * pUnit);
	void				UpdateStairState(RECT u);
	pair<bool, RECT>	GetRope(RECT u, float step);
	pair<bool, RECT>	GetBar(RECT u, float step);
};