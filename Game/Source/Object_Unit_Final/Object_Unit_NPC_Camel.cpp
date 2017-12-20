#include "Object_Unit_NPC_Camel.h"
#include "Object_Unit_Savila.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Camel::Object_Unit_NPC_Camel(RECT u) : Object_Unit("Camel") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("pedal", 10);
	mIsSpitOut = false;
	mParty = Friend;
}

void Object_Unit_NPC_Camel::StartAnimation() {
	mAni.SetCycleIndex(1);
}

void Object_Unit_NPC_Camel::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 1) {
		mIsSpitOut = false;
	}
	else if (mAni.GetCycleIndex() == 5 && !mIsSpitOut) {
		mIsSpitOut = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Savila(xx + 122, yy - 26));
	}
}