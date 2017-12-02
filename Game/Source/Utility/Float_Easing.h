#pragma once
#define accelTime 0.3f
enum Ease {
	in,
	linear,
	out,
	stop
};

class Float_Easing {
private:
	float  mVelocity;
	double mValue;
	double mNext;

	Ease mEase;
public:
	Float_Easing() {
		mVelocity = 0;
		mEase = Ease::stop;
	};
	// Gán giá trị mặc định
	void operator<<(float pValue) {
		mValue = mNext = pValue;
	}
	// Gán giá trị mới
	void operator=(float pNext) {
		mNext = pNext;
	}

	void Update(float delay) {
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
	float operator()(float delay) {
		Update(delay);
		return float(mValue);
	}
};
