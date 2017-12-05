#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <vector>
#include <functional> 
#include <string> 

using namespace std;

class Object;
class Object_Animation {
private:
	string	mState;
	int		mCycleIndex;

	string  mNextState;
	int		mNextCycleIndex;
	bool	mSkipNextFrame;
public:
	Object_Animation();

	void NextFrame(Object * pObject);

	void SetState(string pState);
	string GetState();

	string * State();

	int GetFrameIndex(Object * pObject);

	int GetCycleIndex();

	bool SetCycleIndex(int pCycleIndex);
	bool Set(string pState, int pCycleIndex);
	bool Set(string pState, int pCycleIndex, string pNextState, int pNextCycleIndex);

	bool SetNext(string pNextState, int pNextCycleIndex);
	bool Next();
};