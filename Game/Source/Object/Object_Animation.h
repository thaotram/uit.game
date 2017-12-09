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
	string  mNextState;
	
	int		mCycleIndex;
	int		mNextCycleIndex;

	bool	mSkipNextFrame;
public:
	Object_Animation();


	void	NextFrame(Object * pObject);
	
	string	GetState();
	int		GetFrameIndex(Object * pObject);
	int		GetCycleIndex();
	
	bool	Set(string pState, int pCycleIndex);
	bool	Set(string pState, int pCycleIndex, string pNextState, int pNextCycleIndex);
	bool	SetCycleIndex(int pCycleIndex);

	bool	SetNext(string pNextState, int pNextCycleIndex);
	bool	Next();
};