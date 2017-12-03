#pragma once
#include "Object_Map_AgrabahMarket_Back.h"
#include "../Scene/Scene.h"
#define I GameGlobal::Input

// Khai báo
Object_Map_AgrabahMarket_Back::Object_Map_AgrabahMarket_Back() : Object_Map("AgrabahMarket") {
	mAnimation.Set("back", 1);
}

void Object_Map_AgrabahMarket_Back::ObjectUpdateEvent(float delay) {
	if (I[UP])			mScene->mCamera = V2{ 120, MAP_HEIGHT - HEIGHT };
	if (I[LEFT])		mScene->mCamera = V2{ 60, MAP_HEIGHT - HEIGHT };
	if (I[RIGHT])		mScene->mCamera = V2{ 300, MAP_HEIGHT - HEIGHT };
	if (I[DOWN])		mScene->mCamera = V2{ 0  , MAP_HEIGHT - HEIGHT };
}