#include "Object_Unit_Static_Black_Magic_Lamp.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Black_Magic_Lamp::Object_Unit_Static_Black_Magic_Lamp(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("black_magiclamp", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Static_Black_Magic_Lamp::ObjectIntersect(Object * pObject)
{
	mAutoNextFrame = true;
	mScene->AddToRemoveList(this);
}

void Object_Unit_Static_Black_Magic_Lamp::ObjectUpdateEvent(float dt)
{
}
