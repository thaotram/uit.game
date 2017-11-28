#include "Map.h"

Map::Map(string pName) : Object(pName) {
	// Do something here
	mPosition = { 0,0 };

	
}

void Map::ObjectRender(float delay) {
	//if (mAutoNextFrame) {
	//	if (mCurrentTime >= mTimePerFrame) {
	//		mCurrentTime -= mTimePerFrame;
	//		mAnimation.NextFrame(this);
	//	}
	//	else mCurrentTime += delay;
	//}
	BeforeRender(delay);

	mSourceRect = mScene->mCameraPosition.BOUND(
		D3DXVECTOR2(WIDTH, HEIGHT)
	);
	mTransform.Update(this);
	ObjectDraw(mTransform, mSourceRect, mPosition);
}
