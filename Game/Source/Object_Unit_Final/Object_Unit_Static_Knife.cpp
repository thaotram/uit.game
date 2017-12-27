#pragma once
#include "Object_Unit_Static_Knife.h"

#define mAni mAnimation
#define mPos mPosition
#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Static_Knife::Object_Unit_Static_Knife(float x, float y)
	: Object_Unit("Item") {
	mPos.x << x;
	mPos.y << y;
	mAni.Set("knife", 1);
	mAutoNextFrame = false;
}
void Object_Unit_Static_Knife::ObjectUpdateEvent(float dt) {}