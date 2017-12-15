#include "Object_Unit_Static_Block_Drop.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Block_Drop::Object_Unit_Static_Block_Drop(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	mAni.Set("apple_item", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Static_Block_Drop::ObjectUpdateEvent(float dt) {
	//
}
