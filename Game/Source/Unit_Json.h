#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>

#include <json.hpp>
#include "GameDebug.h"
#include "Unit_Animation.h"

using namespace std;
using json = nlohmann::json;

struct Frame;
typedef Frame FRAME;
struct State;
typedef State STATE;
class Json;
typedef Json UNIT_JSON;

struct Frame {
	Frame() {}
	Frame(
		RECT inRect, D3DXVECTOR2 inTranslation
	) : Rect(inRect), Transition(inTranslation) {}
	RECT Rect;
	D3DXVECTOR2 Transition;
};

struct State {
	State() {};
	State(
		D3DXVECTOR2 pBasePoint, vector<int> pFrameCycle, map<int, FRAME> pFrame
	) : BasePoint(pBasePoint), FrameCycle(pFrameCycle), FrameList(pFrame) {};

	D3DXVECTOR2				BasePoint;
	vector<int>				FrameCycle;
	map<int, FRAME>	FrameList;
};

class Animation;

class Json : public map<string, STATE> {
private:
	STATE operator[](string pState);
public:
	Json() {};
	void operator<<(string pName);

	RECT GetFrame(string mState, int mFrameIndex);
	D3DXVECTOR2 GetTransition(string pState, int pFrameIndex);
	D3DXVECTOR2 GetBasePoint(string pState, int pFrameIndex);
	vector<int> GetFrameCycle(string pState);

	RECT GetFrame(Animation * pAnimation);
	D3DXVECTOR2 GetTransition(Animation * pAnimation);
	D3DXVECTOR2 GetBasePoint(Animation * pAnimation);
	vector<int> GetFrameCycle(Animation * pAnimation);
};
