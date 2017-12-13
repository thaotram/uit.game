#include "Object_Unit_Static_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Unit_Static_Apple::Object_Unit_Static_Apple(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	//mPos << V2{ 1900, 400 };
	mAni.Set("apple_item", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Static_Apple::ObjectUpdateEvent(float dt)
{

}