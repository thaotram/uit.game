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

struct Frame {
	Frame() {}
	Frame(
		RECT inRect, D3DXVECTOR2 inTranslation
	) : Rect(inRect), Transition(inTranslation) {}
	RECT Rect;
	D3DXVECTOR2 Transition;
};

typedef Frame UNIT_FRAME;

class Animation : public map<
	string,
	pair<D3DXVECTOR2, pair<vector<int>, map<int, UNIT_FRAME>>>
> {
private:
	string	mState;
	int		mFrame;
	int		mCycleIndex;
public:
	Animation();
	void Initialization(string filePath);;

	void NextFrame();
	RECT GetFrame();
	D3DXVECTOR2 GetTransition();
	D3DXVECTOR2 GetBasePoint();

	void SetState(string pState);
	string GetState();
};

typedef Animation UNIT_ANIMATION;