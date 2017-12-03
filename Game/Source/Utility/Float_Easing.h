#pragma once
enum Ease {
	in,
	linear,
	out,
	stop,
	run
};

class Float_Easing {
private:
	float
		mTime,
		mNow,
		mLast,
		mBack,
		pxps;
	float mAuto;
	Ease	mEase;
public:
	Float_Easing();

	void operator<<(float pValue);	// mặc định

	void operator=(float pNext);	// mới
	void operator+=(float pNext);	// mới
	void operator-=(float pNext);	// mới

	void SetAuto(float pAuto);
	void Update(float delay);
	float operator()();
};
