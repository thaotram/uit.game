#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>

#define D GameDebug::Title

Float_Easing::Float_Easing() {
	mTime = 0;
	mAuto = 0;
	mEase = Ease::stop;
	mNow = 0;
}
void Float_Easing::operator<<(float pValue) {
	mNow = mLast = pValue;
}

void Float_Easing::operator=(float pLast) {
	mLast = pLast;
	mTime = 0;
	mBack = mNow;
	pxps = 300;
}
void Float_Easing::operator+=(float pDelta) {
	*this = mLast + pDelta;
}
void Float_Easing::operator-=(float pDelta) {
	*this = mLast - pDelta;
}

void Float_Easing::SetAuto(float pAuto) {
	mAuto = pAuto;
	mTime = 0;
	mBack = mNow;
}

void Float_Easing::Update(float dt = 0) {
	mTime += dt;
	if (mAuto != 0) {
		mNow = mBack + mTime * mAuto;
	}
}
float Float_Easing::operator()() {
	return float(mNow);
}