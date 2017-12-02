#pragma once
enum Ease {
	in,
	linear,
	out,
	stop
};

class Float_Easing {
private:
	float
		mTime,
		mNow,
		mNext,
		mBack,
		pxps;
	Ease	mEase;
public:
	Float_Easing();

	void operator<<(float pValue);	// mặc định

	void operator=(float pNext);	// mới
	void operator+=(float pNext);	// mới
	void operator-=(float pNext);	// mới

	void Update(float delay);
	float operator()();
};
