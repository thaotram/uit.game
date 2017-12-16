#include "Object_Map_Block.h"
#include "../Object/Object.h"
#include "../Object_Unit_Final/Object_Unit_Static_Block_Drop.h"
#include "../GameDebug.h"
#include <math.h>

//# Object_Map_Block
#define add(kind)					\
json kind = block[#kind];			\
for (auto& s : kind) {				\
	m##kind.push_back(				\
		RECT{s[0],s[1],s[2],s[3]}	\
	);								\
}

Object_Map_Block::Object_Map_Block(string pName) {
	pName = "Resources/" + pName + ".json";
	ifstream i(pName);
	json j;
	i >> j;

	json block = j["block"];

	add(Bar);
	add(Rope);
	add(Square);
	add(Stairs_slash);
	add(Stairs_backslash);

	add(_Square);
	add(_Stairs_slash);
	add(_Stairs_backslash);

	add(Abubonus);
	add(Apple);
	add(Block_Drop);
	add(Black_Magic_Lamp);
	add(Extra_Health);
	add(Genie_Bonus);
	add(Restart_Point);
	add(Spend_These);

	mStairsState = StairsState::Bot;
	mStairsStateOld = StairsState::Bot;
}

//# GetDistance
#define check_square(v, value) long v = value; out.v = (v >= 0 && (v < out.v || out.v == -1)) ? v : out.v

#define check_squares(x,y) {		\
	check_square(x, u.x - b->y);	\
	check_square(y, b->x - u.y);	\
}

#define check_stair(uy)												\
if (b->bottom >= u.bottom) {										\
	LONG b_height = b->bottom - b->top;								\
	LONG b_weight = b->right - b->left;								\
	LONG u_y = max(uy, 0);											\
	LONG u_x = min(b_height * u_y / b_weight, b_height);			\
	out.bottom = min(out.bottom, (b->bottom - u_x) - u.bottom);		\
}

#define if_in(x,y)	if(u.x > b.y && b.x > u.y)
#define if_inptr(x,y)	if(u.x > b->y && b->x > u.y)
#define filter(var)										\
for (auto &b : m##var) {								\
	if_in(right, left) 		top_bottom.push_back(&b);	\
	if_in(bottom, top)		left_right.push_back(&b);	\
}														\

#define filterLeftRight(var)							\
for (auto &b : m##var) {								\
	if_in(right, left) 		top_bottom.push_back(&b);	\
}

#define clearFilter()	\
left_right.clear();		\
top_bottom.clear();		\

RECT Object_Map_Block::GetDistance(RECT u, Object * pUnit) {
	RECT out = { -1,-1,-1,-1 };

	//# Filter
	list<RECT *> left_right;
	list<RECT *> top_bottom;

	//# Square
	filter(Square);
	if (mStairsState == StairsState::Mid ||
		mStairsState == StairsState::Top) filterLeftRight(_Square);
	for (auto &b : left_right)	check_squares(left, right);
	for (auto &b : top_bottom)	check_squares(top, bottom);
	clearFilter();

	// Chỉ tỉnh toán bottom, không quan tâm các thể loại khác
	//# Stairs Slash
	filter(Stairs_slash);
	if (mStairsState == StairsState::Top) filterLeftRight(_Stairs_slash);
	for (auto &b : top_bottom)	check_stair(u.right - b->left);
	clearFilter();

	//# Stairs Backslash
	filter(Stairs_backslash);
	if (mStairsState == StairsState::Mid) filterLeftRight(_Stairs_backslash);
	for (auto &b : top_bottom)	check_stair(b->right - u.left);
	clearFilter();

	GameDebug::TitleCount();

	//# Block_Drop
	for (auto &unit : *(pUnit->mScene)) {		// Đây là filter
		if (unit->mIsRender) {
			if (dynamic_cast<Object_Unit_Static_Block_Drop *>(&*unit)) {
				auto block = (Object_Unit_Static_Block_Drop *)(&*unit);
				auto b = new RECT(block->GetBound());
				if_inptr(right, left)	top_bottom.push_back(b);
			}
		}
	}
	for (auto &b : top_bottom)	check_squares(top, bottom);
	for (auto &b : top_bottom)	delete b;
	clearFilter();

	return out;
}

const int maxRight = 2611;
const int maxLeft = 2291;
void Object_Map_Block::UpdateStairState(RECT u) {
	auto unitMid = (u.right + u.left) / 2;
	if (mStairsState == mStairsStateOld) {
		if (unitMid <= maxLeft) {
			switch (mStairsState) {
			case Mid:
				mStairsState = Top;
				break;
			case Top:
				mStairsState = Mid;
				break;
			}
		}
		else if (unitMid >= maxRight) {
			switch (mStairsState) {
			case Mid:
				mStairsState = Bot;
				break;
			case Bot:
				mStairsState = Mid;
				break;
			}
		}
	}
	else if (maxLeft <= unitMid && unitMid <= maxRight) {
		mStairsStateOld = mStairsState;
	}
}

//# Get Rope
pair<bool, RECT> Object_Map_Block::GetRope(RECT u, float step) {
	bool is = false;
	RECT out = { 0,0,0,0 };
	for (auto &b : mRope) {
		if (u.bottom <= b.bottom &&
			u.top >= b.top &&
			abs((u.left + u.right) - (b.left + b.right)) <= 2 * step) {
			is = true;
			out = b;
			break;
		}
	}
	return pair<bool, RECT>(is, out);
}

//# Get Bar
pair<bool, RECT> Object_Map_Block::GetBar(RECT u, float step) {
	bool is = false;
	RECT out = { 0,0,0,0 };
	for (auto &b : mBar) {
		if (u.left >= b.left &&
			u.right <= b.right &&
			u.top <= b.top &&
			u.bottom > b.bottom &&
			u.top + step >= b.top && step >= 0) {
			is = true;
			if (b.top < out.top || out.top == 0) {
				out = b;
			}
		}
	}
	return pair<bool, RECT>(is, out);
}