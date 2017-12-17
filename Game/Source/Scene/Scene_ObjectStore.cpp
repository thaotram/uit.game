#include "Scene_ObjectStore.h"
#include <math.h>
#include "../Object/Object.h"
#include "../Object_Unit_Final/Object_Unit_Static_Abubonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Static_Black_Magic_Lamp.h"
#include "../Object_Unit_Final/Object_Unit_Static_Block_Drop.h"
#include "../Object_Unit_Final/Object_Unit_Static_Extra_Health.h"
#include "../Object_Unit_Final/Object_Unit_Static_Genie_Bonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Restart_Point.h"
#include "../Object_Unit_Final/Object_Unit_Static_Spend_These.h"
#include "../Object_Unit_Final/Object_Unit_Static_Stick.h"

#include "../Object_Unit_Final/Object_Unit_Enemy_Assassin.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Circus.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Fat.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Pirates.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Straw.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Thin.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Camel.h"
#include "../Object_Unit_Final/Object_Unit_NPC_Peddler.h"

#include "../GameDebug.h"

//# Scene_Block_Store
#define add_unit(kind)					\
json kind = block[#kind];				\
for (auto& s : kind) {					\
	m##kind.push_back(					\
		make_pair(						\
			RECT{s[0],s[1],s[2],s[3]},	\
			nullptr						\
		)								\
	);									\
}

#define add_ground(kind)				\
json kind = block[#kind];				\
for (auto& s : kind) {					\
	m##kind.push_back(					\
		RECT{s[0],s[1],s[2],s[3]}		\
	);									\
}

Scene_ObjectStore::Scene_ObjectStore(string pName) {
	pName = "Resources/" + pName + ".json";
	ifstream i(pName);
	json j;
	i >> j;

	json block = j["block"];

	add_ground(Bar);
	add_ground(Rope);
	add_ground(Square);
	add_ground(Stairs_slash);
	add_ground(Stairs_backslash);

	add_ground(_Square);
	add_ground(_Stairs_slash);
	add_ground(_Stairs_backslash);

	add_unit(Static_Abubonus);
	add_unit(Static_Apple);
	add_unit(Static_Block_Drop);
	add_unit(Static_Black_Magic_Lamp);
	add_unit(Static_Extra_Health);
	add_unit(Static_Genie_Bonus);
	add_unit(Static_Restart_Point);
	add_unit(Static_Spend_These);
	add_unit(Static_Stick);

	add_unit(NPC_Camel);
	add_unit(NPC_Peddler);

	add_unit(Enemy_Assassin);
	add_unit(Enemy_Circus);
	add_unit(Enemy_Fat);
	add_unit(Enemy_Pirates);
	add_unit(Enemy_Straw);
	add_unit(Enemy_Thin);

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

#define if_in(x,y)		if(u.x > b.y && b.x > u.y)
#define if_inptr(x,y)	if(u.x > b->y && b->x > u.y)
#define filter_ground(var)									\
for (auto &b : m##var) {									\
	if_in(right, left) 		top_bottom.push_back(&b);	\
	if_in(bottom, top)		left_right.push_back(&b);	\
}

#define filter_ground_LeftRight(var)					\
for (auto &b : m##var) {								\
	if_in(right, left) 		top_bottom.push_back(&b);	\
}

#define clearFilter()	\
left_right.clear();		\
top_bottom.clear();		\

void Scene_ObjectStore::ObjectUpdateEvent(float dt) {
	for (auto &unit : mStatic_Apple) {
		auto b = unit.first;
		auto c = mScene->mCamera;
		if (b.top < c.y + HEIGHT &&
			b.bottom > c.y &&
			b.left < c.x + WIDTH &&
			b.right > c.x) {
			if (unit.second == nullptr || unit.second == NULL) {
				unit.second = new Object_Unit_Static_Apple(b);
				unit.second->mScene = mScene;
			}
			unit.second->ObjectUpdateEvent(dt);
		}
		else {
			if (unit.second != NULL) {
				delete unit.second;
				unit.second = NULL;
			}
		}
	}
}

void Scene_ObjectStore::ObjectRender(float dt) {
	for (auto &b : mStatic_Apple) {
		if (b.second != NULL) {
			b.second->ObjectRender(dt);
		}
	}
}

RECT Scene_ObjectStore::GetDistance(RECT u, Object * pUnit) {
	RECT out = { -1,-1,-1,-1 };

	//# Filter
	list<RECT *> left_right;
	list<RECT *> top_bottom;

	//# Square
	filter_ground(Square);
	if (mStairsState == StairsState::Mid ||
		mStairsState == StairsState::Top) filter_ground_LeftRight(_Square);
	for (auto &b : left_right)	check_squares(left, right);
	for (auto &b : top_bottom)	check_squares(top, bottom);
	clearFilter();

	// Chỉ tỉnh toán bottom, không quan tâm các thể loại khác
	//# Stairs Slash
	filter_ground(Stairs_slash);
	if (mStairsState == StairsState::Top) filter_ground_LeftRight(_Stairs_slash);
	for (auto &b : top_bottom)	check_stair(u.right - b->left);
	clearFilter();

	//# Stairs Backslash
	filter_ground(Stairs_backslash);
	if (mStairsState == StairsState::Mid) filter_ground_LeftRight(_Stairs_backslash);
	for (auto &b : top_bottom)	check_stair(b->right - u.left);
	clearFilter();

	//# Block_Drop
	for (auto &pair : mStatic_Block_Drop) {		// Đây là filter
		if (pair.second != nullptr) {
			auto block = (Object_Unit_Static_Block_Drop *)(pair.second);
			auto b = new RECT(block->GetBound());
			if_inptr(right, left)	top_bottom.push_back(b);
		}
	}
	for (auto &b : top_bottom)	check_squares(top, bottom);
	for (auto &b : top_bottom)	delete b;
	clearFilter();

	return out;
}

const int maxRight = 2611;
const int maxLeft = 2291;
void Scene_ObjectStore::UpdateStairState(RECT u) {
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
pair<bool, RECT> Scene_ObjectStore::GetRope(RECT u, float step) {
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
pair<bool, RECT> Scene_ObjectStore::GetBar(RECT u, float step) {
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

//# Get Stick
pair<bool, RECT> Scene_ObjectStore::GetStick(RECT u, float step) {
	bool is = false;
	RECT out = { 0,0,0,0 };
	//for (auto &b : mStatic_Stick) {
	//	if (u.left >= b.left &&
	//		u.right <= b.right &&
	//		u.top <= b.top &&
	//		u.bottom > b.bottom &&
	//		u.top + step >= b.top && step >= 0) {
	//		is = true;
	//		if (b.top < out.top || out.top == 0) {
	//			out = b;
	//		}
	//	}
	//}
	return pair<bool, RECT>(is, out);
}