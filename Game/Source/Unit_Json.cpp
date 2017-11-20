#include "Unit_Json.h"

void Json::Initialization(string filePath) {
	this->clear();
	try {
		ifstream i(filePath);
		json j;
		i >> j;

		json states = j["states"];
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
			map<int, FRAME> p_frameList;
			for (
				json::iterator frame = j_frame.begin();
				frame != j_frame.end();
				++frame
				)
			{
				json f = frame.value();
				p_frameList[stoi(frame.key())] = FRAME(
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
				STATE(p_basePoint, p_frameCycle, p_frameList)
			);
		}
	}
	catch (exception e) {
		this->clear();
	}
}

STATE Json::operator[](string pState) {
	return find(pState)->second;
}

RECT Json::GetFrame(string pState, int pFrameIndex) {
	return (*this)[pState].FrameList[pFrameIndex].Rect;
}
D3DXVECTOR2 Json::GetTransition(string pState, int pFrameIndex) {
	return (*this)[pState].FrameList[pFrameIndex].Transition;
}
D3DXVECTOR2 Json::GetBasePoint(string pState, int pFrameIndex) {
	return (*this)[pState].BasePoint;
}
vector<int> Json::GetFrameCycle(string pState) {
	return (*this)[pState].FrameCycle;
}
