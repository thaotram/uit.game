#include "Unit.h"
int oldF;
Unit::Unit(string name, D3DCOLOR color)
{
	state = 1;
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

		RECT rectSize;
		json jsonSize, jsonFrameLine;
		D3DXVECTOR2 transition;
		map<int, int> frameLine;

		json states = j["states"];
		mTimePerFrame = j["time"];
		data.clear();
		int stateIndex = 1;
		for (auto& state : states) {
			json frames = state["frame"];

			int frameIndex = 1;
			for (json::iterator frame = frames.begin(); frame != frames.end(); ++frame) {
				jsonSize = frame.value()[0];
				rectSize = RECT{
					(LONG)jsonSize[0],
					(LONG)jsonSize[1],
					(LONG)jsonSize[0] + (LONG)jsonSize[2],
					(LONG)jsonSize[1] + (LONG)jsonSize[3]
				};
				transition = D3DXVECTOR2(jsonSize[4], jsonSize[5]);

				jsonFrameLine = frame.value()[1];
				Frame *framePointer;
				framePointer = &data[stateIndex][stoi(frame.key())];
				*framePointer = Frame{ rectSize, transition };
				// jsonFrameLine = frame.value()[1];
				// framePointer->FrameLine[1] = 0;
				for (json::iterator it = jsonFrameLine.begin(); it != jsonFrameLine.end(); ++it) {
					if (it.key() == "?")
						framePointer->FrameLine[0] = (int)it.value();
					else
						framePointer->FrameLine[stoi(it.key())] = (int)it.value();
				}
			}
			stateIndex++;
		}
	}
	catch (exception e) {
		// throw "Lỗi khi cố gắng đọc file Json";
		data.clear();
	}
	return;
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
	// Change Name to Frame
	{
		string s1 = "Frame: " + to_string(frame);
		wstring s2;
		s2.assign(s1.begin(), s1.end());
		LPCTSTR Title = s2.c_str();
		SetWindowText(
			GameGlobal::GetCurrentHWND(),
			Title
		);
	}

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
		//if (!data.empty())
		//	// return data[state].first[frame].first;
	}
	catch (exception e) {}
	RECT sample;
	sample.top = 0;
	sample.left = 0;
	sample.right = 100;
	sample.bottom = 100;
	return sample;
}
D3DXVECTOR2 Unit::GetTranslation(int state, int cycle)
{
	if (data.empty()) return D3DXVECTOR2();

	D3DXVECTOR2 scale = mSprite->GetScale();
	//D3DXVECTOR2 trans = data[state].first[cycle].second;
	//return D3DXVECTOR2(scale.x * trans.x, scale.y * trans.y);
	return D3DXVECTOR2();
}

void Unit::NextFrame()
{
	//int nextCycle = data[state].second[frame].second;
	//if (
	//	data[state].second.find(nextCycle) !=
	//	data[state].second.end()
	//	) {
	//	//? Sửa chố này, thêm cái thay đổi frame vào
	//	// cycle = nextCycle; //data[state].second[nextCycle].first;

	//	// frame = GetFrame(state, cycle);
	//}
	//else {
	//	int a = 0;
	//}
}