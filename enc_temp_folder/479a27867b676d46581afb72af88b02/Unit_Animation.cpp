#include "Unit_Animation.h"
#include "Unit.h"
#include "Unit_Entity.h"

Unit_Animation::Unit_Animation() {
	mState = "";
	//mFrameIndex = 1;
	mCycleIndex = 1;
}

void Unit_Animation::NextFrame(Unit * pUnit, Unit_Entity * pEntity) {
	vector<int> pFrameCycle = pUnit->GetJson()->GetFrameCycle(mState);
	int nextFrame = pFrameCycle[mCycleIndex + 1];
	if (nextFrame == 0) {
		pEntity->mEndFunction();
	}
	else if (nextFrame > 0) {
		mCycleIndex++;
	}
	else {
		mCycleIndex = -nextFrame;
	}
}

void Unit_Animation::SetState(string pState) {
	mState = pState;
}
string Unit_Animation::GetState() {
	return mState;
}

int Unit_Animation::GetFrameIndex(Unit * pUnit) {
	vector<int> pFrameCycle = pUnit->GetJson()->GetFrameCycle(mState);
	return pFrameCycle[mCycleIndex];
}

int Unit_Animation::GetCycleIndex() {
	return mCycleIndex;
}
void Unit_Animation::SetCycleIndex(int pCycleIndex) {
	mCycleIndex = pCycleIndex;
}

void Unit_Animation::Set(string pState, int pCycleIndex) {
	mState = pState;
	mCycleIndex = pCycleIndex;
}
