#pragma once
enum Ease {
	in,
	out,
	stop
};
enum Type {
	linear,
	quad
};

class Float_Easing {
private:
	float
		mTime,
		mBack, mNext, mNow, mLast,
		pxps;
public:
	Float_Easing();
	Ease	mEase, mNextEase;
	Type	mType;

	float	mMaxTime;

	void operator<<(float pValue);	// mặc định

	void operator=(float pNext);	// mới
	void operator+=(float pNext);	// mới
	void operator-=(float pNext);	// mới

	void Update(float delay);
	float operator()();
};
