#include "Object_Unit_NPC_Stall.h"
#include "Object_Unit_NPC_Peddler.h"

#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Stall::Object_Unit_NPC_Stall(RECT u) : Object_Unit("Peddler") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("stalls", 1);
	isShow = false;
}

Object_Unit_NPC_Stall::~Object_Unit_NPC_Stall()
{
}

void Object_Unit_NPC_Stall::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 48 && !isShow) {
		isShow = true;
		auto r = RECT{ 
			(LONG)mPos.x(),
			(LONG)mPos.y(),
			(LONG)mPos.x(),
			(LONG)mPos.y()
		};
		mScene->oObjectStore->mNPC_Peddler.push_back(pair<RECT, Object *>(
			r,
			nullptr
		));
	}
}
