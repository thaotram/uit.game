#include "Unit.h"

Unit::Unit(string name, D3DCOLOR color)
{
	state = 1;
	frame = 1;
	string path_ = "Resources/Sprite/" + name + "/" + name + ".png";
	const char * path = path_.c_str();

	mSprite = new Sprite(path, color);
	mSprite->SetRect(
		GetRect(state, frame)
	);
	this->name = name;
	InitializationData(name);
}
Unit::~Unit() {}

Sprite * Unit::GetSprite()
{
	return mSprite;
}

void Unit::InitializationData(string name)
{

	try {
		json j;
		ifstream i;
		i.open("Resources/Sprite/" + name + "/" + name + ".json");
		i >> j;

		RECT size;
		D3DXVECTOR2 transition;

		json states = j["states"];
		mTimePerFrame = j["time"];
		startFrame = j["startFrame"];
		data.clear();
		int stateIndex = 1;
		for (auto& state : states) {
			data[stateIndex];
			json frames = state["frame"];

			int frameIndex = 1;
			for (auto& f : frames) {
				size = RECT{
					(LONG)f[0],
					(LONG)f[1],
					(LONG)f[0] + (LONG)f[2] ,
					(LONG)f[1] + (LONG)f[3]
				};
				transition = D3DXVECTOR2(f[4], f[5]);
				data[stateIndex][frameIndex] =
					pair<RECT, D3DXVECTOR2>(size, transition); // transition {x,y}
				frameIndex++;
			}
			stateIndex++;
		}
	}
	catch (exception e) {
		// throw "Lỗi khi cố gắng đọc file Json";
		data.clear();
	}
}

void Unit::SetState(int state)
{
	this->state = state;
}

void Unit::Update(float dt)
{
	if (data.empty())
		InitializationData(name);
	//if (GetFrameCount(state) <= 1) return;

	if (mCurrentTime >= mTimePerFrame) {
		//mCurrentTime -= mTimePerFrame;
		mCurrentTime = 0;
		NextFrame();
		InitializationData(name);
	}
	else mCurrentTime += dt;
}
void Unit::Draw()
{
	mSprite->SetRect(
		GetRect(state, frame)
	);
	mSprite->SetTranslation(
		GetTranslation(state, frame)
	);
	mSprite->Draw();
}

RECT Unit::GetRect(int state, int frame)
{
	try {
		if (!data.empty()) return data[state][frame].first;
	}
	catch (exception e) {}
	RECT sample;
	sample.top = 0;
	sample.left = 0;
	sample.right = 100;
	sample.bottom = 100;
	return sample;
}

D3DXVECTOR2 Unit::GetTranslation(int state, int frame)
{
	if (data.empty()) return D3DXVECTOR2();

	D3DXVECTOR2 scale = mSprite->GetScale();
	D3DXVECTOR2 trans = data[state][frame].second;
	return D3DXVECTOR2(scale.x * trans.x, scale.y * trans.y);
}

int Unit::GetStateCount()
{
	return data.size();
}
int Unit::GetFrameCount(int state)
{
	if (data.empty()) return 0;
	return data[state].size();
}

void Unit::NextFrame()
{
	frame = frame < GetFrameCount(state) ? frame + 1 : startFrame;
}