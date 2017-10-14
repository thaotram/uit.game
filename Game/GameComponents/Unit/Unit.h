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
	int		cycle;
	int		frame;
	int		startFrame;
	void	NextFrame();

	
	int				GetFrame(int state, int cycle);
	RECT			GetRect(int state, int cycle);
	D3DXVECTOR2		GetTranslation(int state, int cycle);

	void	InitializationData(string);

	float	mTimePerFrame, mCurrentTime;

	map<
		int,
		pair<
			map<int, pair<RECT, D3DXVECTOR2>>,
			map<int, pair<int, int>>
		>
	> data;
public:
	Unit(string name, D3DCOLOR color = NULL);
	~Unit();

	Sprite * GetSprite();

	void SetState(int state);
	void Update(float dt);
	void Draw();
};
