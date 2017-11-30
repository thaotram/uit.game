#include "Vector_Easing.h"
#include <math.h>

Vector_Easing::Vector_Easing() {
	mTranslation = { 0, 0 };
	mCurentTime = 0;
	mTotalTime = 0;
}

void Vector_Easing::StartTranslation(D3DXVECTOR2 pTranslation, float pTotalTime) {
	mCurentTime = 0;
	mTranslation = pTranslation;
	mTotalTime = pTotalTime;
}

D3DXVECTOR2 Vector_Easing::VECTOR2(float delay) {
	/// https://github.com/nicolausYes/easing-functions/blob/master/src/easing.cpp
	mCurentTime += delay;
	float t = mTotalTime == 0
		? 1
		: mCurentTime / mTotalTime;
	float r;
	if (t >= 1) {
		r = 1;
		mTotalTime = 0;
	}
	else {
		r = t < 0.5
			? (float)(4 * pow(t, 3))
			: (float)(4 * pow(t - 1, 3) + 1);
	}
	return mSelf + mTranslation * r;
}