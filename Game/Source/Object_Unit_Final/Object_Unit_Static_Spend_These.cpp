#include "Object_Unit_Static_Spend_These.h"
#define mAni	mAnimation
#define mPos	mPosition
#define xx		mPos.x()
#define yy		mPos.y()

Object_Unit_Static_Spend_These::Object_Unit_Static_Spend_These(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("spendthese_item", 1);
	mAutoNextFrame = true;
	mSourceRect.Update(this);
	tUnit = GetBound();
}

void Object_Unit_Static_Spend_These::ObjectUpdateEvent(float dt) {

}

void Object_Unit_Static_Spend_These::ObjectIntersect(Object * pObject)
{
	Scene::mSpendthese++;
	Scene::mScore += 150;
	mIsMarkedDelete = true;
	Scene::mScene->oObjectStore->mLost.push_back(
		new Object_Unit_Explosion_Twinkle(
			xx - 2, yy - 4,
			Scene::mScene->oPlayer->GetTransform()->GetFlip()
		)
	);
}