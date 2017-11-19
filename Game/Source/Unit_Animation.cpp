﻿#include "Unit_Animation.h"

Animation::Animation() {
	mState = "";
	mFrame = 1;
	mCycleIndex = 1;
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
			vector<int> p_frameCycle(1, 0);
			for (auto& frame : j_frameCycle) {
				p_frameCycle.push_back((int)frame);
			}

			//! frame
			json j_frame = state.value()["frame"];
			map<int, UNIT_FRAME> p_frameList;
			for (
				json::iterator frame = j_frame.begin();
				frame != j_frame.end();
				++frame
				)
			{
				json f = frame.value();
				p_frameList[stoi(frame.key())] = UNIT_FRAME(
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

			this->insert_or_assign(
				state.key(),
				UNIT_STATE(p_basePoint, p_frameCycle, p_frameList)
			);
		}
	}
	catch (exception e) {
		this->clear();
	}
}

void Animation::operator++(int) {
	vector<int> frameCycle = (*this)[mState].FrameCycle;
	int nextFrame = frameCycle[mCycleIndex + 1];
	if (nextFrame > 0) 	mCycleIndex++;
	else				mCycleIndex = -nextFrame;
	mFrame = frameCycle[mCycleIndex];
}
UNIT_STATE Animation::operator[](string pState)
{
	return this->find(pState)->second;
}
RECT Animation::GetFrame() {
	return GetFrame(mState, mFrame);
}
RECT Animation::GetFrame(string pState, int pFrame)
{
	return (*this)[pState].FrameList[pFrame].Rect;
}

D3DXVECTOR2 Animation::GetTransition() {
	return GetTransition(mState, mFrame);
}
D3DXVECTOR2 Animation::GetTransition(string pState, int pFrame) {
	return (*this)[pState].FrameList[pFrame].Transition;
}

D3DXVECTOR2 Animation::GetBasePoint() {
	return GetBasePoint(mState);
}
D3DXVECTOR2 Animation::GetBasePoint(string pState) {
	return (*this)[pState].BasePoint;
}

void Animation::SetState(string pState) {
	mState = pState;
	mFrame = 1;
	mCycleIndex = 1;
}
string Animation::GetState() {
	return mState;
}