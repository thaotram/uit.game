#pragma once
#include "Object_Unit_Static_Extra_Health.h"
#include "Object_Unit_Aladdin.h"

#define mAni	mAnimation
#define mPos	mPosition
#define xx		mPos.x()
#define yy		mPos.y()

Object_Unit_Static_Extra_Health::Object_Unit_Static_Extra_Health(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("extrahealth", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = true;
	mSourceRect.Update(this);
	tUnit = GetBound();
}

void Object_Unit_Static_Extra_Health::ObjectUpdateEvent(float dt)
{

}

void Object_Unit_Static_Extra_Health::ObjectIntersect(Object * pObject)
{
	Scene::mScore += 150;
	Scene::mBlood = min(Scene::mBlood + 1,8);
	mIsMarkedDelete = true;
	Scene::mScene->oObjectStore->mLost.push_back(
		new Object_Unit_Explosion_Twinkle(
			xx - 4, yy - 4,
			Scene::mScene->oPlayer->GetTransform()->GetFlip()
		)
	);
}
