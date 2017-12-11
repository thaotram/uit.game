#pragma once
enum Ease {
	in,
	out,
	stop
};
enum Type {
	gravity,
	quad,
	none
};

class Float_Easing {
private:
	float
		mTime,
		mBack, mNext, mNow, mLast;
public:
	Float_Easing();
	Ease	mEase, mNextEase;
	Type	mType;

	float	mVelocity;
	float	mDuration;

	void operator<<(float pValue);	// mặc định

	void operator=(float pNext);	// mới
	void operator+=(float pNext);	// mới
	void operator-=(float pNext);	// mới

	void Update(float delay);

	float operator()();
};
