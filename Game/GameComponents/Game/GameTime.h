#pragma once
#include <windows.h>

class GameTime
{
private:
	GameTime();
	LARGE_INTEGER mStartTime, mEndTime, mDelta, mClockRate;
	static GameTime *mInstance;
public:
	static GameTime* GetInstance();
	void StartCounter();
	DWORD GetCouter();
	~GameTime();
};