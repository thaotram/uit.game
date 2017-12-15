#include "Object_Unit_Static_Block_Drop.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Block_Drop::Object_Unit_Static_Block_Drop(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	mAni.Set("blockdrop", 1);
	mAutoNextFrame = false;
	isDrop = false;
}

void Object_Unit_Static_Block_Drop::ObjectUpdateEvent(float dt) {
	mPos.Update(dt);
}

void Object_Unit_Static_Block_Drop::ObjectIntersect(Object * pObject){
	if (!isDrop) {
		isDrop = true;
		mPos.y += 40;
	}
}
