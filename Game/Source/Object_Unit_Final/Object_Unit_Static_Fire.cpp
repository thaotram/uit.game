#include "Object_Unit_Static_Fire.h"
#define mAni	mAnimation
#define mPos	mPosition
#define xx		mPos.x()
#define yy		mPos.y()
Object_Unit_Static_Fire::Object_Unit_Static_Fire(RECT u) : Object_Unit("Aladdin"){
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("hurt", 1);
	mAutoNextFrame = false;
	//mSourceRect.Update(this);
	tUnit = u;
}

Object_Unit_Static_Fire::~Object_Unit_Static_Fire()
{
}

void Object_Unit_Static_Fire::ObjectUpdateEvent(float delay)
{
}

void Object_Unit_Static_Fire::ObjectIntersect(Object * pObject)
{
}
