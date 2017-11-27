#pragma once
#include "Map_AgrabahMarket.h"
#include "Scene.h"

Map_AgrabahMarket::Map_AgrabahMarket() : Unit("AgrabahMarket") {
	mPosition = { 0,0 };
	mAnimation.Set("back", 1);
	mAutoNextFrame = false;
}

void Map_AgrabahMarket::AfterAddToScene() {
	RECT pMap = mJson->GetFrame(this);
	mScene->mCameraPosition = {
		0, (float)(pMap.bottom - GameGlobal::GetHeight() / GameGlobal::GetScale())
	};
	mTransform.Update(this);
}

void Map_AgrabahMarket::SelfUpdateBeforeNextFrame() {
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
void Map_AgrabahMarket::UnitRender(float dt) {
	//mScene->mCameraPosition += {2, 0};
	mSourceRect = mScene->mCameraPosition.BOUND(
		GameGlobal::GetSize()
	);
	UnitRenderWithParameter(mTransform, mSourceRect, mPosition);
}