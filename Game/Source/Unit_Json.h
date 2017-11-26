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
class Unit_Json;

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

//class Unit_Animation;
class Unit;

class Unit_Json : public map<string, STATE> {
private:
	static map<string, Unit_Json *> Unit_Jsons;

	STATE operator[](string pState);
	Unit_Json(string pName);
public:
	static Unit_Json * GetJson(string pName);

	RECT GetFrame(string mState, int mFrameIndex);
	D3DXVECTOR2 GetTransition(string pState, int pFrameIndex);
	D3DXVECTOR2 GetBasePoint(string pState, int pFrameIndex);
	vector<int> GetFrameCycle(string pState);

	RECT		GetFrame(Unit * pUnit);
	D3DXVECTOR2 GetTransition(Unit * pUnit);
	D3DXVECTOR2 GetBasePoint(Unit * pUnit);

	vector<int> GetFrameCycle(Unit * pUnit);
};