#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>

Float_Easing::Float_Easing() {
	mTime = 0;
	mEase = Ease::stop;
	mType = Type::none;
	mNow = 0;
}
void Float_Easing::operator<<(float pValue) {
	mNow = mLast = pValue;
}

void Float_Easing::operator=(float pLast) {
	mLast = pLast;
	mTime = 0;
	mDuration = 0.3f;
}
void Float_Easing::operator+=(float pDelta) {
	*this = mLast + pDelta;
}
void Float_Easing::operator-=(float pDelta) {
	*this = mLast - pDelta;
}
float Float_Easing::operator()() {
	return float(mNow);
}

void Float_Easing::Update(float dt = 0) {
	switch (mType) {
	case Type::gravity:		//# Gravity
		switch (mEase) {
		case in:
			mNow += mVelocity * dt;
			mVelocity += dt * 1000;
			if (mNow >= mLast) {
				mEase = Ease::stop;
				mNow = mLast;
				mVelocity = 0;
			}
			break;
		case stop:
			if (mVelocity != 0 || mLast != mNow) {
				mEase = Ease::in;
			}
			break;
		}
		break;
	case Type::none:		//# None
		mNow = mLast;
		break;
	}
}

void Float_Easing::ppp(float delay) {

}