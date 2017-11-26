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
	int		mCycleIndex;

	string  mNextState;
	int		mNextCycleIndex;
	bool	mSkipNextFrame;
public:
	Unit_Animation();

	void NextFrame(Unit * pUnit);

	void SetState(string pState);
	string GetState();

	string * State();

	int GetFrameIndex(Unit * pUnit);

	int GetCycleIndex();
	void SetCycleIndex(int pCycleIndex);

	void Set(string pState, int pCycleIndex);
	void Set(string pState, int pCycleIndex, string pNextState, int pNextCycleIndex);
};