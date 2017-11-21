﻿#pragma once
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
public:
	Unit_Animation();

	void NextFrame(Unit * pJson, Unit_Entity * pEntity);

	void SetState(string pState);
	string GetState();

	string * State();

	int GetFrameIndex(Unit * pUnit);

	int GetCycleIndex();
	void SetCycleIndex(int pCycleIndex);

	void Set(string pState, int pCycleIndex);
	void Set(string pState, int pCycleIndex, string pNextState, int pNextCycleIndex);
};