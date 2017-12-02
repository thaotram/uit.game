#include "Float_Easing.h"
#define	accelTime 0.3f

Float_Easing::Float_Easing() {
	mVelocity = 0;
	mEase = Ease::stop;
	mValue = 0;
}

void Float_Easing::operator<<(float pValue) {
	mValue = mNext = pValue;
}

void Float_Easing::operator+=(float pDelta) {
	mNext += pDelta;
}

void Float_Easing::operator=(float pNext) {
	mNext = pNext;
}

void Float_Easing::Update(float delay) {
	switch (mEase)
	{
	case Ease::in:
		mVelocity += delay;
		if (mVelocity > accelTime) {
			mVelocity = accelTime;
			mEase = Ease::linear;
		}
		break;
	case Ease::linear:
		break;
	case Ease::out:
		break;
	case Ease::stop:
		break;
	default:
		break;
	}
}

float Float_Easing::operator()() {
	return float(mValue);
}
