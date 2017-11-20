#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <vector>
#include <functional> 

#include "GameDebug.h"

class Unit;
class Unit_Entity;

class Unit_Animation {
private:
	string	mState;
	int		mFrameIndex;
	int		mCycleIndex;
public:
	Unit_Animation();
	
	// Thay đổi FrameIndex, CycleIndex
	void NextFrame(Unit * pJson, Unit_Entity * pEntity);

	void SetState(string pState);
	string GetState();

	int GetFrameIndex();
	void SetFrameIndex(int pFrameIndex);;

	int GetCycleIndex();
	void SetCycleIndex(int pCycleIndex);

	void Set(string pState, int pFrameIndex, int pCycleIndex);
};