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
	mScene->Add(mScene->itPlayer, new Object_Unit_Explosion_Big(mPos.x()+20,mPos.y()));
}

void Object_Unit_Static_Black_Magic_Lamp::ObjectUpdateEvent(float dt)
{
}
