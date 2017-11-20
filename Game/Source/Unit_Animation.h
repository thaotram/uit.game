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
#include "Unit_Json.h"

using namespace std;
using json = nlohmann::json;

class Animation;
typedef Animation UNIT_ANIMATION;

class Animation : public map<string, STATE> {
private:
	string	mState;
	int		mFrameIndex;
	int		mCycleIndex;
public:
	Animation();
	void Initialization(string filePath);;

	// Đi đến Frame tiếp theo
	void operator++(int);

	STATE operator[](string pState);

	RECT GetFrame();
	D3DXVECTOR2 GetTransition();
	D3DXVECTOR2 GetBasePoint();

	void SetState(string pState);
	string GetState();

	int GetFrameIndex();
	void SetFrameIndex(int pFrameIndex);;

	int GetCycleIndex();
	void SetCycleIndex(int pCycleIndex);
};
