#include "Object_Unit_NPC_Peddler.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Peddler::Object_Unit_NPC_Peddler(RECT u) : Object_Unit("Peddler") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("peddler_show", 1);
}

Object_Unit_NPC_Peddler::~Object_Unit_NPC_Peddler() {
}