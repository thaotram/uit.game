#pragma once
#include "Object_Unit_Static_Knife.h"

#define mAni mAnimation
#define mPos mPosition
#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Static_Knife::Object_Unit_Static_Knife()
	: Object_Unit("Item") {
	//mPos.x << (float)(u.left);
	//mPos.y << (float)(u.top);
	mAni.Set("knife", 1);
	mAutoNextFrame = false;
	mSound = new GameSound(L"Sound/SFX/Apple Collect.wav");
	// mSourceRect.Update(this);
	//tUnit = u;
}
void Object_Unit_Static_Knife::ObjectUpdateEvent(float dt) {}

void Object_Unit_Static_Knife::ObjectIntersect(Object* pObject) {
	Scene::mApple = min(Scene::mApple + 1, 99);
	mIsMarkedDelete = true;
	mSound->Play();
	//Scene::mScene->oObjectStore->mLost.push_back(
	//	//new Object_Unit_Explosion_Twinkle(
	//	//	xx - 6, yy - 6, Scene::mScene->oPlayer->GetTransform()->GetFlip()
	//	)
	//);
}