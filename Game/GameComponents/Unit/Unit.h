#pragma once
#include "../Sprite/Sprite.h"
#include <iostream>
#include <fstream>
#include <map>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

typedef struct Frame {
	Frame() {};
	Frame(
		RECT	      inRect,
		D3DXVECTOR2   inTranslation
	) :
		Rect(inRect),
		Transition(inTranslation)
	{
		FrameLine.clear();
	}
	RECT Rect;
	D3DXVECTOR2 Transition;
	map<int, int> FrameLine;
} Frame;

class Unit
{
private:
	Sprite * mSprite;

	string	name;
	int		state;
	int		frame;
	int		previousFrame;
	void	NextFrame();

	RECT			GetRect(int state, int cycle);
	D3DXVECTOR2		GetTranslation(int state, int cycle);

	void	InitializationData(string);

	float	mTimePerFrame, mCurrentTime;

	map<int, map<int, Frame>> data;
public:
	Unit(string name, D3DCOLOR color = NULL);
	~Unit();

	Sprite * GetSprite();

	void SetState(int state);
	void SetFrame(int frame);
	void Update(float dt);
	void Draw();
};
