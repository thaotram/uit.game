#include "Object_Unit_Static_Restart_Point.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Unit_Static_Restart_Point::Object_Unit_Static_Restart_Point(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	//mPos << V2{ 1900, 400 };
	mAni.Set("restartpoint", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Static_Restart_Point::ObjectUpdateEvent(float dt)
{

}