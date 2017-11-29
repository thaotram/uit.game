#pragma once
#include "Object_Map_AgrabahMarket_Back.h"
#include "../Scene/Scene.h"

// Khai báo
Object_Map_AgrabahMarket_Back::Object_Map_AgrabahMarket_Back() : Object_Map("AgrabahMarket") {
	mAnimation.Set("back", 1);
}

void Object_Map_AgrabahMarket_Back::ObjectUpdateEvent(float delay) {
	auto I = GameGlobal::Input;

	if (I[UP])  mScene->mCameraPosition;
		
		// ->SetTranslation({ 20,50 }, 1);
	//if (I[DOWN])    mScene->mCameraPosition += {0, 2};
	//if (I[LEFT])    mScene->mCameraPosition -= {2, 0};
	//if (I[RIGHT])   mScene->mCameraPosition += {2, 0};
}