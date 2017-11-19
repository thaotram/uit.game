#include "Unit_Animation.h"

Animation::Animation() {
	mFrame = 1;
	mCycleIndex = 1;
	mState = "";
}

void Animation::Initialization(string filePath) {
	this->clear();
	try {
		ifstream i(filePath);
		json j;
		i >> j;

		json states = j["states"];
		if (mState == "") mState = states.begin().key();
		for (json::iterator state = states.begin(); state != states.end(); ++state)
		{
			//! basePoint
			D3DXVECTOR2	p_basePoint;
			try {
				p_basePoint = {
					state.value()["basePoint"][0],
					state.value()["basePoint"][1]
				};
			}
			catch (exception e) {
				p_basePoint = { 0,0 };
			}

			//! frameCycle
			json j_frameCycle = state.value()["frameCycle"];
			vector<int> p_frameCycle;
			for (auto& frame : j_frameCycle) {
				p_frameCycle.push_back((int)frame);
			}

			//! frame
			json j_frame = state.value()["frame"];
			map<int, UNIT_FRAME> p_frame;
			for (
				json::iterator frame = j_frame.begin();
				frame != j_frame.end();
				++frame
				)
			{
				json f = frame.value();
				p_frame[stoi(frame.key())] = UNIT_FRAME(
					RECT{
					(LONG)f[0],
					(LONG)f[1],
					(LONG)f[0] + (LONG)f[2],
					(LONG)f[1] + (LONG)f[3]
				},
					D3DXVECTOR2(
					(float)f[4],
						(float)f[5]
					)
				);
			}
			auto mmm = state.key();
			this->insert_or_assign(state.key(), make_pair(p_basePoint, make_pair(p_frameCycle, p_frame)));
		}
	}
	catch (exception e) {
		this->clear();
	}
}

void Animation::NextFrame() {
	//! Đếm từ 0 và đếm từ 1 => phải trừ 1
	//!? cycles[index - 1]
	vector<int> cycles = this->find(mState)->second.second.first;
	int nextFrame = cycles[mCycleIndex + 1 - 1];
	if (nextFrame > 0) 	mCycleIndex++;
	else				mCycleIndex = -nextFrame;
	mFrame = cycles[mCycleIndex - 1];
}
RECT Animation::GetFrame() {
	return this->find(mState)->second.second.second[mFrame].Rect;
}

D3DXVECTOR2 Animation::GetTransition() {
	return this->find(mState)->second.second.second[mFrame].Transition;
}
D3DXVECTOR2 Animation::GetBasePoint() {
	return this->find(mState)->second.first;
}
void Animation::SetState(string pState) {
	mState = pState;
	mFrame = 1;
	mCycleIndex = 1;
}
string Animation::GetState() {
	return mState;
}
