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

//enum BlockType {
//	rope,
//	apple,
//	black_magiclamp,
//	spendthese_item,
//	geniebonus,
//	abubonus,
//	restartpoint,
//	extrahealth,
//	woodenbar,
//	square,
//	stairs_slash,
//	stairs_backslash
//};

class Object;

class Object_Map_Block {
private:
	list<RECT>			mRope;
	list<RECT>			mBar;
	list<RECT>			mSquare;
	list<RECT>			mStairs_slash;
	list<RECT>			mStairs_backslash;
public:
	Object_Map_Block(string pName);
	~Object_Map_Block() {};

	//# Static Item
	list<RECT> mAbubonus;
	list<RECT> mApple;
	list<RECT> mBlack_Magic_Lamp;
	list<RECT> mExtra_Health;
	list<RECT> mGenie_Bonus;
	list<RECT> mRestart_Point;
	list<RECT> mSpend_These;

	RECT				GetDistance(RECT u);
	pair<bool, RECT>	GetRope(RECT u, float step);
	pair<bool, RECT>	GetBar(RECT u, float step);
};