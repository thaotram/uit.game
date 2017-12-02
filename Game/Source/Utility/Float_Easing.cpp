#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>

//#define	pxps 50
#define f float
#define at 0.1f		// accel time

#define D GameDebug::Title
// 50 px/s => 1s

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
	pxps = 20; // (mNext - mNow) / 2;
}
void Float_Easing::operator+=(float pDelta) {
	*this = mNext + pDelta;
}
void Float_Easing::operator-=(float pDelta) {
	*this = mNext - pDelta;
}

void Float_Easing::Update(float dt) {
	switch (mEase) {
	case Ease::in:
		mTime += dt;
		if (mTime >= at) {
			mEase = Ease::linear;
			mTime -= at;
			mBack += pxps;
			Update(0);
			// 1s là khoảng thời gian nó đi đến vị trí (1,1) trên đồ thị
		}
		else {
			mNow = mBack + (f)pow(mTime / at, 3) * pxps;
		}
		break;
	case Ease::linear:
		mTime += dt;
		if (mTime >= (mNext - mBack - pxps) / pxps / 3 * at) {
			mEase = Ease::out;
			mTime -= (mNext - mBack - pxps) / pxps / 3 * at;
			mBack = mNext - pxps;
			Update(0);
		}
		else {
			mNow = mBack + 3 * (mTime / at) * pxps;
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
			mNow = mBack + ((f)pow((mTime / at) - 1, 3) + 1) * pxps;
		}
		break;
	case Ease::stop:
		mTime = 0;
		if (mNext != mNow) {
			mEase = Ease::in;
			mBack = mNow;
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