#include "Float_Easing.h"
#include "../GameDebug.h"
#include <math.h>

//#define	pxps 50
//#define f float
//#define at 2.f		// accel time
float at = 0.3f;

#define D GameDebug::Title
#define is_Next_Mid min(mBack, mLast) <= mNext && mNext <= max(mBack, mLast)

Float_Easing::Float_Easing() {
	mTime = 0;
	mEase = Ease::stop;
	mNow = 0;
}
void Float_Easing::operator<<(float pValue) {
	mNow = mLast = pValue;
}

void Float_Easing::operator=(float pNext) {
	mLast = pNext;
	pxps = 80; // (mNext - mNow) / 2;
}
void Float_Easing::operator+=(float pDelta) {
	*this = mLast + pDelta;
}
void Float_Easing::operator-=(float pDelta) {
	*this = mLast - pDelta;
}

void Float_Easing::Update(float dt) {
	// init
	float maxTime;

	if (mNow != 462) {
		GameDebug::Title(
			"Back:" + to_string(mBack)
			+ " - Now:" + to_string(mNow)
			+ " - Next:" + to_string(mNext)
			+ " - px/s:" + to_string(pxps)
		);
	}

	switch (mEase) {
	case Ease::in:
		mTime += dt;
		if (mTime >= at) {
			if (abs(mLast - mNext) <= pxps) {
				mEase = Ease::out;
				mTime -= at;
				swap(mBack, mNext);
				mNext = mLast;
				Update(0);
			}
			else {
				mEase = Ease::linear;
				mTime -= at;
				swap(mBack, mNext);
				mNext = mNext + mLast - mBack;
				Update(0);
			}
			// 1s là khoảng thời gian nó đi đến vị trí (1,1) trên đồ thị
		}
		else {
			if (isBack == true || min(mBack, mLast) <= mNext && mNext <= max(mBack, mLast)) {
				mNow = mBack + (mNext - mBack) * pow(mTime / at, 3);
			}
			else {
				// Đổi chiều
				mEase = Ease::out;
				mTime = at - mTime;
				auto nNext = mNow + mNow - mBack;
				auto nBack = mNow + mNow - mNext;
				mNext = nNext;
				mBack = nBack;
				isBack = true;
				Update(0);
			}
		}
		break;
	case Ease::linear:
		mTime += dt;
		maxTime = (abs(mNext - mBack) * at) / (pxps * 3);
		if (mTime >= maxTime) {
			mEase = Ease::out;
			mTime -= maxTime;
			swap(mBack, mNext);
			mNext = mLast;
			Update(0);
		}
		else {
			if (is_Next_Mid) {
				mNow = mBack + (mNext > mBack ? 1 : -1) * (3 * (mTime / at)) * pxps;
			}
			else {
				// Đổi chiều
				mEase = Ease::out;
				mBack = mNow;
				mNext = mNow + (mNext > mNow ? 1 : -1) * pxps;
				mTime = 0;
				isBack = true;
				Update(0);
			}
		}
		break;
	case Ease::out:
		mTime += dt;

		if (pxps >abs(mNext - mBack)) {
			pxps = abs(mNext - mBack);
		}

		if (mTime >= at) {
			if (isBack == true) {
				mEase = Ease::in;
				mTime -= at;
				swap(mBack, mNext);
				isBack = false;

				if (abs(mLast - mBack) < 2 * abs(mBack - mNext)) {
					pxps = abs(mLast - mBack) / 2;
					mNext = (mLast + mBack) / 2;
				}

				Update(0);
			}
			else {
				mEase = Ease::stop;
				mTime -= at;
				mNow = mBack = mNext = mLast;
				Update(0);
			}
		}
		else {
			if (isBack == true || mLast == mBack || is_Next_Mid) {
				mNow = mBack + (mNext > mBack ? 1 : -1) * (pow((mTime / at) - 1, 3) + 1) * pxps;
			}
			else {
				// Đổi chiều
				// Nếu last != back và không phải đang đổi chiều ở cái khác
				isBack = true;
				Update(0);
			}
		}
		break;
	case Ease::stop:
		if (mLast != mNow) {
			mEase = Ease::in;
			mTime = 0;
			if (abs(mLast - mNow) < pxps * 2) {
				pxps = abs(mLast - mNow) / 2;
			}
			mBack = mNow;
			mNext = mNow + (mLast > mNow ? 1 : -1) * pxps;
			isBack = false;

			Update(dt);
		}
		else {}
		break;
	}
}
float Float_Easing::operator()() {
	return float(mNow);
}