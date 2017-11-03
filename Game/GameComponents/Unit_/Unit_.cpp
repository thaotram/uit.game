#include "Unit.h"
#include "..\Node\Unit.h"

Unit_::Unit_(string mName, D3DCOLOR color)
{
	mState = 1;
	mFrame = 1;
	mPreviousFrame = 0;
	string path_ = "Resources/Sprite/" + mName + "/" + mName + ".png";
	const char * path = path_.c_str();

	mSprite = new Sprite(path, color);
	mSprite->SetRect(
		GetRect(mState, mFrame)
	);
	this->mName = mName;
	InitializationData(mName);
}
Unit_::~Unit_() {}

Sprite * Unit_::GetSprite()
{
	return mSprite;
}

void Unit_::InitializationData(string mName)
{
	try {
		json j;
		ifstream i;
		i.open("Resources/Sprite/" + mName + "/" + mName + ".json");
		i >> j;

		RECT rectSize;
		json jsonSize, jsonFrameLine;
		D3DXVECTOR2 transition;
		map<int, int> frameLine;

		json states = j["states"];
		mTimePerFrame = j["time"];
		data.clear();
		int stateIndex = 1;
		for (auto& mState : states) {
			json frames = mState["frame"];

			int frameIndex = 1;
			for (json::iterator mFrame = frames.begin(); mFrame != frames.end(); ++mFrame) {
				jsonSize = mFrame.value()[0];
				rectSize = RECT{
					(LONG)jsonSize[0],
					(LONG)jsonSize[1],
					(LONG)jsonSize[0] + (LONG)jsonSize[2],
					(LONG)jsonSize[1] + (LONG)jsonSize[3]
				};
				transition = D3DXVECTOR2(jsonSize[4], jsonSize[5]);

				jsonFrameLine = mFrame.value()[1];
				Frame *framePointer;
				framePointer = &data[stateIndex][stoi(mFrame.key())];
				*framePointer = Frame{ rectSize, transition };
				for (json::iterator it = jsonFrameLine.begin(); it != jsonFrameLine.end(); ++it) {
					if (it.key() == "?") {
						framePointer->FrameLine[0] = (int)it.value();
					}
					else {
						framePointer->FrameLine[stoi(it.key())] = (int)it.value();
					}
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

void Unit_::SetState(int mState)
{
	this->mState = mState;
}

void Unit_::SetFrame(int mFrame)
{
	this->mFrame = mFrame;
}

void Unit_::Update(float dt)
{
	if (data.empty()) InitializationData(mName);

	if (mCurrentTime >= mTimePerFrame) {
		//mCurrentTime -= mTimePerFrame;
		mCurrentTime = 0;
		NextFrame();
		InitializationData(mName);
	}
	else mCurrentTime += dt;
}
void Unit_::Draw()
{
	// Change Name to Frame
	{
		string s1 = "Frame: " + to_string(mFrame);
		wstring s2;
		s2.assign(s1.begin(), s1.end());
		LPCTSTR Title = s2.c_str();
		SetWindowText(
			GameGlobal::GetCurrentHWND(),
			Title
		);
	}

	mSprite->SetRect(
		GetRect(mState, mFrame)
	);
	mSprite->SetTranslation(
		GetTranslation(mState, mFrame)
	);
	mSprite->Draw();
}

RECT Unit_::GetRect(int mState, int mFrame)
{
	try {
		if (!data.empty())
			return data[mState][mFrame].Rect;
	}
	catch (exception e) {}
	RECT sample;
	sample.top = 0;
	sample.left = 0;
	sample.right = 100;
	sample.bottom = 100;
	return sample;
}
D3DXVECTOR2 Unit_::GetTranslation(int mState, int cycle)
{
	if (data.empty()) return D3DXVECTOR2();

	D3DXVECTOR2 scale = mSprite->GetScale();
	D3DXVECTOR2 trans = data[mState][mFrame].Transition;
	return D3DXVECTOR2(scale.x * trans.x, scale.y * trans.y);
}

void Unit_::NextFrame()
{
	int currentFrame = mFrame;
	map<int, int> * f = &data[mState][currentFrame].FrameLine;
	mFrame = f->at(f->find(mPreviousFrame) == f->end() ? 0 : mPreviousFrame);
	mPreviousFrame = currentFrame;
}