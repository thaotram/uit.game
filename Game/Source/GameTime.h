#pragma once
#include <windows.h>

class GameTime
{
private:
	static LARGE_INTEGER mStartTime, mEndTime, mFrequency;
public:
	static void StartCounter();
	static float GetCounter();
};