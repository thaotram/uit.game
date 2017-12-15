#include "Object_Unit_NPC_Peddler.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Peddler::Object_Unit_NPC_Peddler(float x1, float x2, float y) : Object_Unit("Peddler"){
	mPos << V2{ (x1 + x2) / 2 , y };
	mAni.Set("stalls", 1);
}

Object_Unit_NPC_Peddler::~Object_Unit_NPC_Peddler()
{
}
