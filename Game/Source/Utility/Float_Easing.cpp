﻿#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>

//#define	pxps 50
#define f float
#define at 1.f		// accel time

#define D GameDebug::Title

Float_Easing::Float_Easing() {
	mTime = 0;
	mEase = Ease::stop;
	mNow = 0;
}
void Float_Easing::operator<<(float pValue) {
	mNow = mNext = pValue;
}

void Float_Easing::operator=(float pNext) {
	mNext = pNext;
	pxps = 80; // (mNext - mNow) / 2;
}
void Float_Easing::operator+=(float pDelta) {
	*this = mNext + pDelta;
}
void Float_Easing::operator-=(float pDelta) {
	*this = mNext - pDelta;
}

void Float_Easing::Update(float dt) {
	// init
	float maxTime;

	switch (mEase) {
	case Ease::in:
		mTime += dt;
		if (mTime >= at) {
			mEase = Ease::linear;
			mTime -= at;
			mBack = mBack + flag * pxps;
			Update(0);
			// 1s là khoảng thời gian nó đi đến vị trí (1,1) trên đồ thị
		}
		else {
			mNow = mBack + flag * (f)pow(mTime / at, 3) * pxps;
		}
		break;
	case Ease::linear:
		mTime += dt;
		maxTime = (abs(mNext - mBack) - pxps) / pxps / 3 * at;
		if (mTime >= maxTime) {
			mEase = Ease::out;
			mTime -= maxTime;
			mBack = mNext - flag * pxps;
			Update(0);
		}
		else {
			mNow = mBack + flag * 3 * (mTime / at) * pxps;
		}
		break;
	case Ease::out:
		mTime += dt;
		if (mTime >= at) {
			mTime = 0;
			mNow = mBack = mNext;
			mEase = Ease::stop;
			Update(0);
		}
		else {
			mNow = mBack + flag * ((f)pow((mTime / at) - 1, 3) + 1) * pxps;
		}
		break;
	case Ease::stop:
		mTime = 0;
		if (mNext != mNow) {
			mEase = Ease::in;
			mBack = mNow;
			flag = mNext > mNow ? 1 : -1;
			Update(dt);
		}
		else {
			mNow = mBack = mNext;
		}
		break;
	}
}
float Float_Easing::operator()() {
	return float(mNow);
}