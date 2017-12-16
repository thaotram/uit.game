#pragma once
enum Ease {
	in,
	out,
	stop
};
enum Type {
	gravity,
	none,
	linear
};

class Float_Easing {
private:
	float
		mBack, mNext, mNow, mLast;
public:
	Float_Easing();
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
