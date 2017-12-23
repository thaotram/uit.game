#include "Object_Json.h"
#include "Object.h"

map<string, Object_Json *> Object_Json::Object_Jsons;

Object_Json::Object_Json(string pName) {
	pName = "Resources/" + pName + ".json";
	this->clear();
	try {
		ifstream i(pName);
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

Object_Json * Object_Json::GetJson(string pName){
	// return new Object_Json(pName);
	if (Object_Jsons.find(pName) == Object_Jsons.end()) {
		Object_Jsons[pName] = new Object_Json(pName);
	}
	return Object_Jsons.at(pName);
}

STATE Object_Json::operator[](string pState) {
	return find(pState)->second;
}

RECT Object_Json::GetFrame(string pState, int pFrameIndex) {
	return (*this)[pState].FrameList[pFrameIndex].Rect;
}
D3DXVECTOR2 Object_Json::GetTransition(string pState, int pFrameIndex) {
	return (*this)[pState].FrameList[pFrameIndex].Transition;
}
D3DXVECTOR2 Object_Json::GetBasePoint(string pState, int pFrameIndex) {
	return (*this)[pState].BasePoint;
}
vector<int> Object_Json::GetFrameCycle(string pState) {
	return (*this)[pState].FrameCycle;
}

RECT Object_Json::GetFrame(Object * pObject) {
	return GetFrame(
		pObject->GetAnimation()->GetState(),
		pObject->GetAnimation()->GetFrameIndex(pObject)
	);
}
D3DXVECTOR2 Object_Json::GetTransition(Object * pObject) {
	return GetTransition(
		pObject->GetAnimation()->GetState(),
		pObject->GetAnimation()->GetFrameIndex(pObject)
	);
}
D3DXVECTOR2 Object_Json::GetBasePoint(Object * pObject) {
	return GetBasePoint(
		pObject->GetAnimation()->GetState(),
		pObject->GetAnimation()->GetFrameIndex(pObject)
	);
}
vector<int> Object_Json::GetFrameCycle(Object * pObject) {
	return GetFrameCycle(
		pObject->GetAnimation()->GetState()
	);
}
