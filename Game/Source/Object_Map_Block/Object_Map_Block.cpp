#include "Object_Map_Block.h"
#include "../Object/Object.h"
#include "../GameDebug.h"
#include <math.h>

#define bb b->second

struct Bool_RECT {
	Bool_RECT() {};
	Bool_RECT(
		bool pLeft, bool pTop, bool pRight, bool pBottom
	) : left(pLeft), top(pTop), right(pRight), bottom(pBottom) {};
	bool left;
	bool top;
	bool right;
	bool bottom;
};

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
		add(rope);
		add(woodenbar);
		add(stairs_slash);
		add(stairs_backslash);
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
	Bool_RECT bout = { false, false, false, false };
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
				out.bottom = min(out.bottom, (bb.bottom - u_x) - u.bottom);
			}
			break;
		case BlockType::stairs_backslash:
			if (bb.bottom >= u.bottom) {
				LONG b_height = bb.bottom - bb.top;
				LONG b_weight = bb.right - bb.left;
				LONG u_y = max(bb.right - u.left, 0);
				LONG u_x = min(b_height * u_y / b_weight, b_height);
				out.bottom = min(out.bottom, (bb.bottom - u_x) - u.bottom);
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

pair<bool, RECT> Object_Map_Block::GetRope(RECT u, float step) {
	bool is = false;
	RECT out = { 0,0,0,0 };
	for (auto &b : *this) {
		if (b.first == BlockType::rope) {
			if (u.bottom <= b.second.bottom &&
				u.top >= b.second.top &&
				abs((u.left + u.right) - (b.second.left + b.second.right)) <= 2 * step) {
				is = true;
				out = b.second;
				break;
			}
		}
	}
	return make_pair(is, out);
}

pair<bool, RECT> Object_Map_Block::GetWoodenBar(RECT u, float step) {
	bool is = false;
	RECT out = { 0,0,0,0 };
	for (auto &b : *this) {
		if (b.first == BlockType::woodenbar) {
			if (u.left >= b.second.left &&
				u.right <= b.second.right &&
				u.top - 40 <= b.second.top &&
				u.top - 40 + step >= b.second.top) {
				is = true;
				out = b.second;
				break;
			}
		}
	}
	return make_pair(is, out);
}