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

enum BlockType {
	rope,
	apple,
	woodenbar,
	square,
	stairs_slash,
	stairs_backslash
};

class Object;

class Object_Map_Block :public list<pair<BlockType, RECT>> {
public:
	Object_Map_Block(string pName);
	~Object_Map_Block() {};

	RECT				GetDistance(RECT u);
	pair<bool, RECT>	GetRope(RECT u, float step);
	pair<bool, RECT>	GetWoodenBar(RECT u, float step);
};