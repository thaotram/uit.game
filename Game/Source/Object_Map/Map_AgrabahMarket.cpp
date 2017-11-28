#pragma once
#include "Map_AgrabahMarket.h"
#include "../Scene/Scene.h"

// Khai báo
Map_AgrabahMarket::Map_AgrabahMarket() : Map("AgrabahMarket") {
	mAnimation.Set("back", 1);
}

void Map_AgrabahMarket::AfterAddToScene() {
	mTransform.Update(this);
}

void Map_AgrabahMarket::BeforeRender(float delay) {
	map<int, bool> * Key = GameGlobal::GetInput();

	bool K_UP = (*Key)[VK_UP];
	bool K_DOWN = (*Key)[VK_DOWN];
	bool K_LEFT = (*Key)[VK_LEFT];
	bool K_RIGHT = (*Key)[VK_RIGHT];

	if (K_UP) 	  mScene->mCameraPosition -= {0, 2};
	if (K_DOWN)   mScene->mCameraPosition += {0, 2};
	if (K_LEFT)   mScene->mCameraPosition -= {2, 0};
	if (K_RIGHT)  mScene->mCameraPosition += {2, 0};
}