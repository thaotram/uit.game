﻿#include "Object_Map_Block.h"
#include "../Object/Object.h"
#include <math.h>

#define bb b->second

//# Add(type)
#define add(type)					\
json type = block[#type];			\
for (auto& s : type) {				\
	this->push_back(make_pair(		\
		BlockType::type,			\
		RECT{s[0],s[1],s[2],s[3]}	\
	));								\
}

Object_Map_Block::Object_Map_Block(string pName) {
	pName = "Resources/" + pName + ".json";
	this->clear();
	try {
		ifstream i(pName);
		json j;
		i >> j;

		json block = j["block"];

		add(square);
		add(stairs_backslash);
		add(stairs_slash);
	}
	catch (exception e) {
		this->clear();
	}
}

#define check_square(v, value) long v = value; out.v = (v >= 0 && (v < out.v || out.v == -1)) ? v : out.v
#define check_squares(x,y) {			\
	check_square(x, u.x - b->second.y);	\
	check_square(y, b->second.x - u.y);	\
}
#define condition(x,y)	u.x > b.second.y && b.second.x > u.y
RECT Object_Map_Block::GetDistance(RECT u) {
	list<pair<BlockType, RECT> *> left_right;
	list<pair<BlockType, RECT> *> top_bottom;

	RECT out = { -1,-1,-1,-1 };
	for (auto &b : *this) {
		if (condition(right, left)) 		top_bottom.push_back(&b);
		if (condition(bottom, top))			left_right.push_back(&b);
	}
	for (auto &b : top_bottom) {
		switch (b->first) {
		case BlockType::square:
			check_squares(top, bottom);
			break;
		case BlockType::stairs_slash:
			if (bb.bottom >= u.bottom) {
				LONG b_height = bb.bottom - bb.top;
				LONG b_weight = bb.right - bb.left;
				LONG u_y = max(u.right - bb.left, 0);
				LONG u_x = min(b_height * u_y / b_weight, b_height);
				out.bottom = (bb.bottom - u_x) - u.bottom;
			}
			break;
		case BlockType::stairs_backslash:
			if (bb.bottom >= u.bottom) {
				LONG b_height = bb.bottom - bb.top;
				LONG b_weight = bb.right - bb.left;
				LONG u_y = max(bb.right - u.left, 0);
				LONG u_x = min(b_height * u_y / b_weight, b_height);
				out.bottom = (bb.bottom - u_x) - u.bottom;
			}
			break;
		}
	}
	for (auto &b : left_right) {
		switch (b->first) {
		case BlockType::square:
			check_squares(left, right);
			break;
		case BlockType::stairs_slash:
			break;
		}
	}
	return out;
}

