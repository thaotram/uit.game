#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>

#include <json.hpp>

using json = nlohmann::json;
using namespace std;

enum BlockType {
	square
};

class Object;

class Object_Map_Block :public list<pair<BlockType, RECT>> {
public:
	Object_Map_Block(string pName);
	~Object_Map_Block() {};

	float GetGround(Object * pUnit);
	float GetGround(float x, float y);
};