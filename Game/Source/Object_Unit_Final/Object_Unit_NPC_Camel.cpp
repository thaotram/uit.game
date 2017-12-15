#include "Object_Unit_NPC_Camel.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Camel::Object_Unit_NPC_Camel(float x1, float x2, float y) : Object_Unit("Camel") {
	mPos << V2{ (x1 + x2) / 2 , y };
	mAni.Set("pedal", 1);
}

Object_Unit_NPC_Camel::~Object_Unit_NPC_Camel()
{
}
