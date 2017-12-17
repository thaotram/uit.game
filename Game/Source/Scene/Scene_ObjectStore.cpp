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
#include "../Object_Unit_Final/Object_Unit_NPC_Stall.h"
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
	add_unit(NPC_Stall);
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
top_bottom.clear();

#define Object_UpdateEvent_(type, name)							\
for (auto &unit : m##type##name) {								\
	b = unit.first;												\
	c = mScene->mCamera.RECT(V2{ WIDTH, HEIGHT });				\
	if (isIntersect(b, c)) {									\
		if (unit.second == nullptr || unit.second == NULL) {	\
			unit.second = new Object_Unit_##type##name(b);		\
			unit.second->mScene = mScene;						\
		}														\
		unit.second->ObjectUpdateEvent(dt);						\
	}															\
	else if (unit.second != NULL) {								\
		delete unit.second;										\
		unit.second = NULL;										\
	}															\
}
#define Object_UpdateEvent(type, name)	Object_UpdateEvent_(type,_##name)

void Scene_ObjectStore::ObjectUpdateEvent(float dt) {
	RECT b, c;
	Object_UpdateEvent(Static, Abubonus);
	Object_UpdateEvent(Static, Apple);
	Object_UpdateEvent(Static, Block_Drop);
	Object_UpdateEvent(Static, Black_Magic_Lamp);
	Object_UpdateEvent(Static, Extra_Health);
	Object_UpdateEvent(Static, Genie_Bonus);
	Object_UpdateEvent(Static, Restart_Point);
	Object_UpdateEvent(Static, Spend_These);
	Object_UpdateEvent(Static, Stick);

	Object_UpdateEvent(NPC, Camel);
	Object_UpdateEvent(NPC, Stall);
	Object_UpdateEvent(NPC, Peddler);


	Object_UpdateEvent(Enemy, Assassin);
	Object_UpdateEvent(Enemy, Circus);
	Object_UpdateEvent(Enemy, Fat);
	Object_UpdateEvent(Enemy, Pirates);
	Object_UpdateEvent(Enemy, Straw);
	Object_UpdateEvent(Enemy, Thin);
}

//# Object_Render
#define Object_Render_(type, name)	\
for (auto &b : m##type##name) {	   	\
	if (b.second != NULL) {		   	\
		b.second->ObjectRender(dt);	\
	}							   	\
}
#define Object_Render(type, name)		Object_Render_(type, _##name)
void Scene_ObjectStore::ObjectRender(float dt) {
	Object_Render(Static, Abubonus);
	Object_Render(Static, Apple);
	Object_Render(Static, Block_Drop);
	Object_Render(Static, Black_Magic_Lamp);
	Object_Render(Static, Extra_Health);
	Object_Render(Static, Genie_Bonus);
	Object_Render(Static, Restart_Point);
	Object_Render(Static, Spend_These);
	Object_Render(Static, Stick);

	Object_Render(NPC, Camel);
	Object_Render(NPC, Stall);
	Object_Render(NPC, Peddler);

	Object_Render(Enemy, Assassin);
	Object_Render(Enemy, Circus);
	Object_Render(Enemy, Fat);
	Object_Render(Enemy, Pirates);
	Object_Render(Enemy, Straw);
	Object_Render(Enemy, Thin);
}

bool ifMarkedDelete(const pair<RECT, Object *>& p) {
	if (p.second == NULL || p.second == nullptr) return false;
	else if(p.second->mIsMarkedDelete){
		delete p.second;
		return true;
	}
	else {
		return false;
	}
		 
}

#define Object_RemoveMarkedDelete(type, name) Object_RemoveMarkedDelete_(type, _##name)
#define Object_RemoveMarkedDelete_(type, name) m##type##name.remove_if(ifMarkedDelete);
void Scene_ObjectStore::ObjectRemoveMarkedDelete() {
	Object_RemoveMarkedDelete(Static, Apple);
	Object_RemoveMarkedDelete(Static, Block_Drop);
	Object_RemoveMarkedDelete(Static, Black_Magic_Lamp);
	Object_RemoveMarkedDelete(Static, Extra_Health);
	Object_RemoveMarkedDelete(Static, Genie_Bonus);
	Object_RemoveMarkedDelete(Static, Restart_Point);
	Object_RemoveMarkedDelete(Static, Spend_These);
	Object_RemoveMarkedDelete(Static, Stick);

	Object_RemoveMarkedDelete(NPC, Camel);
	Object_RemoveMarkedDelete(NPC, Peddler);

	Object_RemoveMarkedDelete(Enemy, Assassin);
	Object_RemoveMarkedDelete(Enemy, Circus);
	Object_RemoveMarkedDelete(Enemy, Fat);
	Object_RemoveMarkedDelete(Enemy, Pirates);
	Object_RemoveMarkedDelete(Enemy, Straw);
	Object_RemoveMarkedDelete(Enemy, Thin);
}

#define Object_CheckCollision(type, name) Object_CheckCollision_(type, _##name)
#define Object_CheckCollision_(type, name) ObjectCheckCollisionEach(pObject, &m##type##name)
void Scene_ObjectStore::ObjectCheckCollision(Object * pObject) {
	// Làm gì đó bậy bạ trong này
	Object_CheckCollision(Static, Apple);
	Object_CheckCollision(Static, Block_Drop);
	Object_CheckCollision(Static, Black_Magic_Lamp);
	Object_CheckCollision(Static, Extra_Health);
	Object_CheckCollision(Static, Genie_Bonus);
	Object_CheckCollision(Static, Restart_Point);
	Object_CheckCollision(Static, Spend_These);
	Object_CheckCollision(Static, Stick);

	Object_CheckCollision(NPC, Camel);
	Object_CheckCollision(NPC, Stall);
	Object_CheckCollision(NPC, Peddler);

	Object_CheckCollision(Enemy, Assassin);
	Object_CheckCollision(Enemy, Circus);
	Object_CheckCollision(Enemy, Fat);
	Object_CheckCollision(Enemy, Pirates);
	Object_CheckCollision(Enemy, Straw);
	Object_CheckCollision(Enemy, Thin);
}

void Scene_ObjectStore::ObjectCheckCollisionEach(Object * pObject, list<pair<RECT, Object*>>* pList){
	for (auto &unit : *pList) {
		if (unit.second != NULL) {
			if (isIntersect(
				unit.second->GetBound(),
				pObject->GetBound()
			)) {
				auto tDis = this->GetDistance(pObject->tUnit, pObject);
				unit.second->ObjectIntersect(pObject);
			}
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
pair<bool, pair<RECT, Object *> *> Scene_ObjectStore::GetStick(RECT u, float step) {
	bool is = false;
	pair<RECT, Object *> * out = nullptr;
	for (auto &p : mStatic_Stick) {
		auto b = p.first;
		if (u.left <= b.right + 35 &&
			u.right >= b.left &&
			u.bottom < b.bottom &&
			u.bottom + step >= b.bottom && step >= 0) {
			is = true;
			out = &p;
			// Giả như nó chỉ đúng đúng 1 lần
		}
	}
	return pair<bool, pair<RECT, Object *> *>(is, out);
}