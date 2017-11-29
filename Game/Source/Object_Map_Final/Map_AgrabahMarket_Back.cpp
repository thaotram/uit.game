#pragma once
#include "Map_AgrabahMarket_Back.h"
#include "../Scene/Scene.h"

// Khai báo
Map_AgrabahMarket_Back::Map_AgrabahMarket_Back() : Object_Map("AgrabahMarket") {
	mAnimation.Set("back", 1);
}

void Map_AgrabahMarket_Back::ObjectUpdateEvent(float delay) {
	auto I = GameGlobal::Input;

	if (I[UP]) 		mScene->mCameraPosition -= {0, 2};
	if (I[DOWN])    mScene->mCameraPosition += {0, 2};
	if (I[LEFT])    mScene->mCameraPosition -= {2, 0};
	if (I[RIGHT])   mScene->mCameraPosition += {2, 0};
}