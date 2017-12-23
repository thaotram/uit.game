#include "GameTime.h"

LARGE_INTEGER GameTime::mStartTime;
LARGE_INTEGER GameTime::mEndTime;
LARGE_INTEGER GameTime::mFrequency;
float count = 0;
void GameTime::StartCounter() {
	if (!QueryPerformanceFrequency(&mFrequency)) return;
	QueryPerformanceCounter(&mStartTime);
}

float GameTime::GetCounter() {
	QueryPerformanceCounter(&mEndTime);
	return static_cast<float>((mEndTime.QuadPart - mStartTime.QuadPart)) / static_cast<float>(mFrequency.QuadPart);
}