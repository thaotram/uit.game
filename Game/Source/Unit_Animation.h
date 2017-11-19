#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <tuple>

#include <json.hpp>
#include "GameDebug.h"

using namespace std;
using json = nlohmann::json;

struct Frame;
typedef Frame UNIT_FRAME;
struct State;
typedef State UNIT_STATE;

class Animation;
typedef Animation UNIT_ANIMATION;

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
		D3DXVECTOR2 pBasePoint, vector<int> pFrameCycle, map<int, UNIT_FRAME> pFrame
	) : BasePoint(pBasePoint), FrameCycle(pFrameCycle), FrameList(pFrame) {};

	D3DXVECTOR2				BasePoint;
	vector<int>				FrameCycle;
	map<int, UNIT_FRAME>	FrameList;
};

class Animation : public map<
	string,
	UNIT_STATE
> {
private:
	string	mState;
	int		mFrame;
	int		mCycleIndex;
public:
	Animation();
	void Initialization(string filePath);;

	// Đi đến Frame tiếp theo
	void operator++(int);
	
	UNIT_STATE operator[](string pState);

	RECT GetFrame();
	RECT GetFrame(string pState, int pFrame);
	D3DXVECTOR2 GetTransition();
	D3DXVECTOR2 GetTransition(string pState, int pFrame);
	D3DXVECTOR2 GetBasePoint();
	D3DXVECTOR2 GetBasePoint(string pState);

	void SetState(string pState);
	string GetState();
};
