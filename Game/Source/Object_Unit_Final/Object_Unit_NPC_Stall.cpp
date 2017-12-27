#include "Object_Unit_NPC_Stall.h"
#include "Object_Unit_NPC_Peddler.h"

#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Stall::Object_Unit_NPC_Stall(RECT u) : Object_Unit("Peddler") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("stalls", 1);
	isShow = false;
	isPlay = false;
	mParty = Friend;
	mSound = new GameSound(L"Sound/SFX/Peddler Shop.wav");
}

Object_Unit_NPC_Stall::~Object_Unit_NPC_Stall()
{
}

void Object_Unit_NPC_Stall::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 47	 && !isShow) {
		isShow = true;
		if (!isPlay) {
			mSound->Play();
			isPlay = true;
		}
		((Object_Unit *)(Scene::mScene->oObjectStore->mNPC_Peddler.begin()->second))->mAutoNextFrame = true;
	}
}
