#include "Object_Map_Block.h"
#include "../Object/Object.h"
#include <math.h>

Object_Map_Block::Object_Map_Block(string pName) {
	pName = "Resources/" + pName + ".json";
	this->clear();
	try {
		ifstream i(pName);
		json j;
		i >> j;

		json block = j["block"];

		//! square
		json squares = block["square"];
		for (auto& s : squares) {
			this->push_back(make_pair(BlockType::square, RECT{
				(int)s[0],
				(int)s[1],
				(int)s[2],
				(int)s[3]
			}));
		}
	}
	catch (exception e) {
		this->clear();
	}
}

float Object_Map_Block::GetGround(Object * pUnit) {
	float x = pUnit->GetPosition()->GetX()->operator()();
	float y = pUnit->GetPosition()->GetY()->operator()();

	float ground;
	bool f = false;
	for (auto &rect : *this) {
		#define r rect.second
		if (r.left <= x && x <= r.right && y <= r.top) {
			ground = f ? (r.top, ground) : r.top;
			f = true;
		}
	}
	return f ? ground : MAP_HEIGHT;
}