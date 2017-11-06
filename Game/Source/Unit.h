#pragma once
#include "Sprite.h"
#include <iostream>
#include <fstream>
#include <map>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

typedef struct Frame {
	Frame() {};
	Frame(RECT inRect, D3DXVECTOR2 inTranslation) : Rect(inRect), Transition(inTranslation)
	{
		FrameLine.clear();
	}
	RECT Rect;
	D3DXVECTOR2 Transition;
	map<int, int> FrameLine;
} Frame;

class Unit : public Sprite
{
private:
	string  mName;
	int		mState;
	int		mFrame;
	int		mPreviousFrame;
	void	NextFrame();
	string  NameToImagePath(string name);

	RECT			GetRect(int mState, int cycle);
	D3DXVECTOR2		GetTranslation(int mState, int cycle);

	void	InitializationData();

	float	mTimePerFrame, mCurrentTime;

	map<int, map<int, Frame>> mData;
public:
	Unit(string mName, D3DCOLOR color = NULL);
	~Unit() {};

	void SetState(int state) { mState = state; };
	void SetFrame(int frame) { mFrame = frame; };
	void Update(float dt);
	void Draw();
};

