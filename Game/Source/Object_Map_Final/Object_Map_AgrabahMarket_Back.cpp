#pragma once
#include "Object_Map_AgrabahMarket_Back.h"
#include "../Scene/Scene.h"

// Khai báo
Object_Map_AgrabahMarket_Back::Object_Map_AgrabahMarket_Back() : Object_Map("AgrabahMarket") {
	mAnimation.Set("back", 1);
}

void Object_Map_AgrabahMarket_Back::ObjectUpdateEvent(float delay) {
	auto I = GameGlobal::Input;

	if (I[UP])    mScene->mCamera.StartTranslation({ 0,-40 }, 0.2f);
	if (I[DOWN])  mScene->mCamera.StartTranslation({ 0,-40 }, 0.2f);

}