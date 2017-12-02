#pragma once
enum Ease {
	in,
	linear,
	out,
	stop
};

class Float_Easing {
private:
	float	mVelocity;
	float	mValue;
	float	mNext;
	Ease	mEase;
public:
	Float_Easing();

	void operator<<(float pValue);		// Gán giá trị mặc định
	void operator+=(float pDelta);		// Gán giá trị mới
	void operator=(float pNext);		// Gán giá trị mới

	void Update(float delay);
	float operator()();
};
