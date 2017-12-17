#include "Object_Unit_Static_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Apple::Object_Unit_Static_Apple(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("apple_item", 1);
	mAutoNextFrame = false;
}
void Object_Unit_Static_Apple::ObjectUpdateEvent(float dt) {}

void Object_Unit_Static_Apple::ObjectIntersect(Object * pObject) {
	mScene->mApple++;
	mIsMarkedDelete = true;
}