#include "Object_Unit_NPC_Abu.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Abu::Object_Unit_NPC_Abu(float x, float y) : Object_Unit("Abu") {
	mPos << V2{ x , y };
	mAni.Set("faner_carpet", 1);
	mAutoNextFrame = true;
	mParty = Friend;
}

Object_Unit_NPC_Abu::~Object_Unit_NPC_Abu() {}