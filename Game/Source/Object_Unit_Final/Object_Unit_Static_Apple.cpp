#include "Object_Unit_Static_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition
#define xx		mPos.x()
#define yy		mPos.y()

Object_Unit_Static_Apple::Object_Unit_Static_Apple(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("apple_item", 1);
	mAutoNextFrame = false;
	tUnit = GetBound();
}
void Object_Unit_Static_Apple::ObjectUpdateEvent(float dt) {}

void Object_Unit_Static_Apple::ObjectIntersect(Object * pObject) {
	Scene::mScene->mApple++;
	mIsMarkedDelete = true;
	Scene::mScene->oObjectStore->mLost.push_back(
		new Object_Unit_Explosion_Twinkle(
			xx + 5, yy + 6, 
			Scene::mScene->oPlayer->GetTransform()->GetFlip()
		)
	);
}