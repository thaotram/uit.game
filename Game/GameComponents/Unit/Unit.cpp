#include "Unit.h"
int oldF;
Unit::Unit(string name, D3DCOLOR color)
{
	state = 1;
	cycle = 1;
	string path_ = "Resources/Sprite/" + name + "/" + name + ".png";
	const char * path = path_.c_str();

	mSprite = new Sprite(path, color);
	mSprite->SetRect(
		GetRect(state, cycle)
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
			auto p = data[stateIndex];
			json cycles = state["cycle"];
			json frames = state["frame"];

			int cycleIndex = 1;
			for (auto& c : cycles) {
				data[stateIndex].second[cycleIndex] = pair<int, int>(c[0], c[1]);
				cycleIndex++;
			}
			int frameIndex = 1;
			for (auto& f : frames) {
				size = RECT{
					(LONG)f[0],
					(LONG)f[1],
					(LONG)f[0] + (LONG)f[2] ,
					(LONG)f[1] + (LONG)f[3]
				};
				transition = D3DXVECTOR2(f[4], f[5]);
				data[stateIndex].first[frameIndex] =
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
	string s1 = "c: " + to_string(cycle) + " - f: " + to_string(frame);
	wstring s2;
	s2.assign(s1.begin(), s1.end());
	LPCTSTR p = s2.c_str();

	SetWindowText(
		GameGlobal::GetCurrentHWND(),
		p
	);

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
		if (!data.empty())
			return data[state].first[frame].first;
	}
	catch (exception e) {}
	RECT sample;
	sample.top = 0;
	sample.left = 0;
	sample.right = 100;
	sample.bottom = 100;
	return sample;
}
int Unit::GetFrame(int state, int cycle) {
	int f = data[state].second[cycle].first;
	if (f != oldF) {
		oldF = f;
	}
	return f;
}
D3DXVECTOR2 Unit::GetTranslation(int state, int cycle)
{
	if (data.empty()) return D3DXVECTOR2();

	D3DXVECTOR2 scale = mSprite->GetScale();
	D3DXVECTOR2 trans = data[state].first[cycle].second;
	return D3DXVECTOR2(scale.x * trans.x, scale.y * trans.y);
}

void Unit::NextFrame()
{
	int nextCycle = data[state].second[cycle].second;
	if (
		data[state].second.find(nextCycle) !=
		data[state].second.end()
		) {
		cycle = nextCycle; //data[state].second[nextCycle].first;
		frame = GetFrame(state, cycle);
	}
	else {
		int a = 0;
	}

}