#include "Unit_Animation.h"
#include "Unit_Json.h"

Unit_Animation::Unit_Animation() {
	mState = "";
	mFrameIndex = 1;
	mCycleIndex = 1;
}

void Unit_Animation::NextFrame(Unit_Json * pJson) {
	vector<int> pFrameCycle = pJson->GetFrameCycle(mState);
	int nextFrame = pFrameCycle[mCycleIndex + 1];
	if (nextFrame > 0) 	mCycleIndex++;
	else				mCycleIndex = -nextFrame;
	mFrameIndex = pFrameCycle[mCycleIndex];
}

void Unit_Animation::SetState(string pState) {
	mState = pState;
}
string Unit_Animation::GetState() {
	return mState;
}
int Unit_Animation::GetFrameIndex() {
	return mFrameIndex;
}
void Unit_Animation::SetFrameIndex(int pFrameIndex) {
	mFrameIndex = pFrameIndex;
}
int Unit_Animation::GetCycleIndex() {
	return mCycleIndex;
}
void Unit_Animation::SetCycleIndex(int pCycleIndex) {
	mCycleIndex = pCycleIndex;
}
