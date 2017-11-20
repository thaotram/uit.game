#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <vector>

#include "GameDebug.h"

class Json;

class Animation {
private:
	string	mState;
	int		mFrameIndex;
	int		mCycleIndex;
public:
	Animation();
	
	// Thay đổi FrameIndex, CycleIndex
	void NextFrame(Json pJson);

	void SetState(string pState);
	string GetState();

	int GetFrameIndex();
	void SetFrameIndex(int pFrameIndex);;

	int GetCycleIndex();
	void SetCycleIndex(int pCycleIndex);
};

typedef Animation UNIT_ANIMATION;