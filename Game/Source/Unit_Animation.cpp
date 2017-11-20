#include "Unit_Animation.h"
#include "Unit_Json.h"

Animation::Animation() {
	mState = "";
	mFrameIndex = 1;
	mCycleIndex = 1;
}

void Animation::NextFrame(Json pJson) {
	vector<int> pFrameCycle = pJson.GetFrameCycle(mState);
	int nextFrame = pFrameCycle[mCycleIndex + 1];
	if (nextFrame > 0) 	mCycleIndex++;
	else				mCycleIndex = -nextFrame;
	mFrameIndex = pFrameCycle[mCycleIndex];
}

void Animation::SetState(string pState) {
	mState = pState;
}
string Animation::GetState() {
	return mState;
}
int Animation::GetFrameIndex() {
	return mFrameIndex;
}
void Animation::SetFrameIndex(int pFrameIndex) {
	mFrameIndex = pFrameIndex;
}
int Animation::GetCycleIndex() {
	return mCycleIndex;
}
void Animation::SetCycleIndex(int pCycleIndex) {
	mCycleIndex = pCycleIndex;
}
