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
#include "Scene_ObjectStore.define.h"

const V2 margin = V2{ 50,50 };
const int maxRight = 2611;
const int maxLeft = 2291;

//# Constructor
Scene_ObjectStore::Scene_ObjectStore(string pName) {
	pName = "Resources/" + pName + ".json";
	ifstream i(pName);
	json j;
	i >> j;

	json block = j["block"];

	EachGround();
	EachObject(Add_Unit);

	mStairsState = StairsState::Bot;
	mStairsStateOld = StairsState::Bot;
}

//# Hàm thực thi mỗi vòng lặp của Game
void Scene_ObjectStore::ObjectUpdateEvent(float dt) {
	RECT camera = (Scene::mScene->mCamera - margin).RECT(V2{ WIDTH,HEIGHT } +margin * 2);					
	EachObject(Object_UpdateEvent);
	for (auto &b : mLost) {
		b->ObjectUpdateEvent(dt);
	}
}
void Scene_ObjectStore::ObjectRemoveMarkedDelete() {
	EachObject(Object_RemoveMarkedDelete);
	mLost.remove_if(ifMarkedDeleteLost);
}
void Scene_ObjectStore::ObjectRender(float dt) {
	EachObject(Object_Render);
	for (auto &b : mLost) {
		b->ObjectRender(dt);
	}
}

//# Kiểm tra đụng độ
void Scene_ObjectStore::ObjectCheckCollisionEach(Object * pPlayer, list<pair<RECT, Object*>>* pList) {
	for (auto &unit : *pList) {
		if (unit.second != NULL) {
			auto player_bound = pPlayer->GetBound();
			auto player_dame = pPlayer->tUnitDamage;
			auto object_bound = unit.second->GetBound();
			auto object_dame = unit.second->tUnitDamage;
			if (player_dame.top != 0) {
				int a = 123;
			}
			if (isIntersect(
				player_bound, object_bound
			)) unit.second->ObjectIntersect(pPlayer);
			if(isIntersect(
				player_dame, object_bound
			)) unit.second->ObjectGetDame(pPlayer);
			if (isIntersect(
				player_bound, object_dame
			)) pPlayer->ObjectGetDame(pPlayer);
		}
	}
}
void Scene_ObjectStore::ObjectCheckCollision(Object * pObject) {
	EachObject(Object_CheckCollision);
}

//# Tính toán khoảng cách
RECT Scene_ObjectStore::GetDistance(RECT u, Object * pUnit) {
	RECT out = { -1,-1,-1,-1 };

	//# Filter
	list<RECT *> left_right;
	list<RECT *> top_bottom;

	//# Square
	Filter_Ground(Square);
	if (mStairsState == StairsState::Mid ||
		mStairsState == StairsState::Top) Filter_Ground_LeftRight(_Square);
	for (auto &b : left_right)	Check_Squares(left, right);
	for (auto &b : top_bottom)	Check_Squares(top, bottom);
	Clear_Filter();

	// Chỉ tỉnh toán bottom, không quan tâm các thể loại khác
	//# Stairs Slash
	Filter_Ground(Stairs_slash);
	if (mStairsState == StairsState::Top) Filter_Ground_LeftRight(_Stairs_slash);
	for (auto &b : top_bottom)	Check_Stair(u.right - b->left);
	Clear_Filter();

	//# Stairs Backslash
	Filter_Ground(Stairs_backslash);
	if (mStairsState == StairsState::Mid) Filter_Ground_LeftRight(_Stairs_backslash);
	for (auto &b : top_bottom)	Check_Stair(b->right - u.left);
	Clear_Filter();

	//# Block_Drop
	for (auto &pair : mStatic_Block_Drop) {		// Đây là filter
		if (pair.second != nullptr) {
			auto block = (Object_Unit_Static_Block_Drop *)(pair.second);
			auto b = new RECT(block->GetBound());
			If_Pointer(right, left)	top_bottom.push_back(b);
		}
	}
	for (auto &b : top_bottom)	Check_Squares(top, bottom);
	for (auto &b : top_bottom)	delete b;
	Clear_Filter();

	return out;
}

//# Get Rope, Bar, Stick, Camel
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
pair<bool, pair<RECT, Object *> *> Scene_ObjectStore::GetCamel(RECT u, float step) {
	bool is = false;
	pair<RECT, Object *> * out = nullptr;
	for (auto &p : mNPC_Camel) {
		auto b = p.first;
		auto mid = (u.left + u.right) / 2 ;
		if (mid <= b.right &&
			mid >= b.left &&
			u.bottom < b.bottom -22 &&
			u.bottom + step >= b.bottom -22 &&
			step >= 0) {
			is = true;
			out = &p;
			break;
			// Giả như nó chỉ đúng đúng 1 lần
		}
	}
	return pair<bool, pair<RECT, Object *> *>(is, out);
}

//# Update Stair (đi cầu thang nhiều tầng)
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