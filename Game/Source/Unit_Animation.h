#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <vector>

#include "GameDebug.h"

class Unit_Json;

class Unit_Animation {
private:
	string	mState;
	int		mFrameIndex;
	int		mCycleIndex;
public:
	Unit_Animation();
	
	// Thay đổi FrameIndex, CycleIndex
	void NextFrame(Unit_Json * pJson);

	void SetState(string pState);
	string GetState();

	int GetFrameIndex();
	void SetFrameIndex(int pFrameIndex);;

	int GetCycleIndex();
	void SetCycleIndex(int pCycleIndex);
};