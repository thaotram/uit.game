#include "Object_Unit_Knife.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock
#define tSpeedX	400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

//# Ném dao của Fat & Circus

Object_Unit_Knife::Object_Unit_Knife(float x, float y) : Object_Unit("Guards"){
}

Object_Unit_Knife::~Object_Unit_Knife()
{
}

void Object_Unit_Knife::ObjectUpdateEvent(float dt)
{
}

void Object_Unit_Knife::ThrowKnife(bool flip)
{
}
