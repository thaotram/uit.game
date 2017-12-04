#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>

#define D GameDebug::Title
#define MT 0.2f
Float_Easing::Float_Easing() {
	mTime = 0;
	mEase = Ease::stop;
	mType = Type::linear;
	mNow = 0;
}
void Float_Easing::operator<<(float pValue) {
	mNow = mLast = pValue;
}

void Float_Easing::operator=(float pLast) {
	mLast = pLast;
	mTime = 0;
	mDuration = 0.3f;
	pxps = 300;
}
void Float_Easing::operator+=(float pDelta) {
	*this = mLast + pDelta;
}
void Float_Easing::operator-=(float pDelta) {
	*this = mLast - pDelta;
}

void Float_Easing::Update(float dt = 0) {
	switch (mType) {
	case Type::linear:					//! ----- LINEAR -----
		switch (mEase) {
		case Ease::stop:
			if (mNow != mLast) {
				mEase = Ease::in;
				mTime = dt;
				mBack = mNow;
				mNext = mLast;
				Update();
			}
			break;
		case Ease::in:
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
		}
		break;
	}
}
float Float_Easing::operator()() {
	return float(mNow);
}