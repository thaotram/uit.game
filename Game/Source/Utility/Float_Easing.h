#pragma once
enum Ease {
	in,
	out,
	stop
};
enum Type {
	gravity,
	linear,
	none,
	pull
};

class Float_Easing {
private:
	float
		mTime,
		mBack, mNext, mNow, mLast;
public:
	Float_Easing();
	Float_Easing(float pStart, Type pType, float pVelocity);
	Ease	mEase, mNextEase;
	Type	mType;

	float	mVelocity;

	void operator<<(float pValue);	// mặc định

	void operator=(float pNext);	// mới
	void operator+=(float pNext);	// mới
	void operator-=(float pNext);	// mới

	void Update(float delay);

	bool SetVelocity(float value);
	float operator()();
};
