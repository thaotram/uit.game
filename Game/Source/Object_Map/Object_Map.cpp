#include "Object_Map.h"
#include <bitset>

Object_Map::Object_Map(string pName) : Object(pName) {
	mPosition = { 0,0 };
}

inline void Object_Map::AfterAddToScene() {
	mTransform.Update(this);
}

void Object_Map::ObjectUpdateProperties()
{
	//if (mAutoNextFrame) {
	//	if (mCurrentTime >= mTimePerFrame) {
	//		mCurrentTime -= mTimePerFrame;
	//		mAnimation.NextFrame(this);
	//	}
	//	else mCurrentTime += delay;
	//}
	mSourceRect = mScene->mCameraPosition.BOUND(
		D3DXVECTOR2(WIDTH, HEIGHT)
	);
}
