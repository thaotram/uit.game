#include "Object_Animation.h"
#include "Object.h"

Object_Animation::Object_Animation() {
	mState = "";
	mCycleIndex = 1;
}

void Object_Animation::NextFrame(Object * pObject) {
	if (mSkipNextFrame) {
		mSkipNextFrame = false;
		return;
	}

	vector<int> pFrameCycle = pObject->GetJson()->GetFrameCycle(mState);
	int nextFrame = pFrameCycle[mCycleIndex + 1];
	if (nextFrame == 0)			Next();
	else if (nextFrame > 0)		mCycleIndex++;
	else						mCycleIndex = -nextFrame;
}

string Object_Animation::GetState() {
	return mState;
}

string Object_Animation::GetNextState()
{
	return mNextState;
}

int Object_Animation::GetFrameIndex(Object * pObject) {
	vector<int> pFrameCycle = pObject->GetJson()->GetFrameCycle(mState);
	return pFrameCycle[mCycleIndex];
}

int Object_Animation::GetCycleIndex() {
	return mCycleIndex;
}
bool Object_Animation::SetCycleIndex(int pCycleIndex) {
	mCycleIndex = pCycleIndex;
	return true;
}
bool Object_Animation::Next() {
	Set(mNextState, mNextCycleIndex);
	return true;
}
bool Object_Animation::Set(string pState, int pCycleIndex, string pNextState, int pNextCycleIndex) {
	Set(pState, pCycleIndex);
	SetNext(pNextState, pNextCycleIndex);
	return true;
}
bool Object_Animation::Set(string pState, int pCycleIndex) {
	mSkipNextFrame = true;
	if (mState != pState) {
		mState = pState;
		mCycleIndex = pCycleIndex;
	}
	return true;
}
bool Object_Animation::SetNext(string pNextState, int pNextCycleIndex) {
	mNextState = pNextState;
	mNextCycleIndex = pNextCycleIndex;
	return true;
}