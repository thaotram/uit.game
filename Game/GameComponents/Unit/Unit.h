#pragma once
#include "../Sprite/Sprite.h"
#include <iostream>
#include <fstream>
#include <map>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

class Unit
{
private:
	Sprite * mSprite;

	string	name;
	int		state;
	int		frame;
	int		GetStateCount();
	int		GetFrameCount(int state);
	void	NextFrame();

	RECT			GetRect(int state, int frame);
	D3DXVECTOR2		GetTranslation(int state, int frame);

	void	InitializationData(string);

	float	mTimePerFrame, mCurrentTime;

	map<int,map<int, pair<RECT, D3DXVECTOR2>>> data;
public:
	Unit(string name, D3DCOLOR color = NULL);
	~Unit();

	Sprite * GetSprite();

	void SetState(int state);
	void Update(float dt);
	void Draw();
};
