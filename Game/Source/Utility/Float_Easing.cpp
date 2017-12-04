#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>

#define D GameDebug::Title
#define MT 0.2f
Float_Easing::Float_Easing() {
	mTime = 0;
	mEase = Ease::stop;
	mType = Type::quad;
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

void Float_Easing::Update(float dt = 0) {
	switch (mType) {
	case Type::gravity:
		switch (mEase) {
		case in:
			mNow += mVelocity * dt * 2;
			mVelocity += dt * 1000;
			break;
		case stop:
			// Do nothing
			break;
		}
		break;
	case Type::quad:					//! ----- LINEAR -----
		switch (mEase) {
		case in:
			mTime += dt;
			if (mTime >= mDuration) {
				mEase = Ease::stop;
				mTime = 0;
				mNow = mBack = mNext;
				Update(0);
			}
			else {
				mNow = mBack + mTime / mDuration * (mNext - mBack);
			}
			break;
		case stop:
			if (mNow != mLast) {
				mEase = Ease::in;
				mTime = dt;
				mBack = mNow;
				mNext = mLast;
				Update();
			}
			break;
		}
		break;
	case Type::none:
		mNow = mLast;
	}
}
float Float_Easing::operator()() {
	return float(mNow);
}