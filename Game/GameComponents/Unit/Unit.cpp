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
		RECT rect;
		i.open("Resources/Sprite/" + name + "/" + name + ".json");
		i >> j;
		json states = j["states"];
		mTimePerFrame = j["time"];
		data.clear();
		int stateIndex = 1;
		for (auto& state : states) {
			data[stateIndex];
			json frames = state["frame"];

			rect.top = state["top"];
			rect.left = state["left"];
			rect.bottom = (state["height"] + rect.top);

			int frameIndex = 1;
			for (auto& frame : frames) {
				rect.left += frame[1]; // + space
				rect.right = (rect.left + frame[0]); // + width
				data[stateIndex][frameIndex] = pair<RECT, LONG>(rect, frame[2]); // & transition
				rect.left = rect.right;
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
	//if (data.empty())
	//	InitializationData(name);
	//if (GetFrameCount(state) <= 1) return;

	if (mCurrentTime >= mTimePerFrame) {
		//mCurrentTime -= mTimePerFrame;
		mCurrentTime = 0;
		NextFrame();
		//InitializationData(name);
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
	return D3DXVECTOR2(data[state][frame].second, 0);
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
	frame = frame < GetFrameCount(state) ? frame + 1 : 1;
}