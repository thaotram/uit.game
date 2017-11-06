#include "Unit.h"

Unit::Unit(string name, D3DCOLOR color) : 
	Sprite(NameToImagePath(name), color)
{
	mName = name;
	mState = 1;
	mFrame = 1;
	mPreviousFrame = 0;

	SetRect(
		GetRect(mState, mFrame)
	);
	InitializationData();
}
void Unit::Update(float dt)
{
	if (mData.empty()) InitializationData();

	if (mCurrentTime >= mTimePerFrame) {
		//mCurrentTime -= mTimePerFrame;
		mCurrentTime = 0;
		NextFrame();
		InitializationData();
	}
	else mCurrentTime += dt;
}
void Unit::Draw()
{
	// For Debug Change Name to Frame
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

	SetRect(
		GetRect(mState, mFrame)
	);
	SetTranslation(
		GetTranslation(mState, mFrame)
	);
	Sprite::Draw();
}
void Unit::NextFrame()
{
	int currentFrame = mFrame;
	map<int, int> * f = &mData[mState][currentFrame].FrameLine;
	mFrame = f->at(f->find(mPreviousFrame) == f->end() ? 0 : mPreviousFrame);
	mPreviousFrame = currentFrame;
}

RECT Unit::GetRect(int state, int frame)
{
	try {
		if (!mData.empty())
			return mData[state][frame].Rect;
	}
	catch (exception e) {}
	return RECT{ 0,0,100,100 };
}

D3DXVECTOR2 Unit::GetTranslation(int state, int frame)
{
	if (mData.empty()) return D3DXVECTOR2();

	D3DXVECTOR2 scale = GetScale();
	D3DXVECTOR2 trans = mData[state][frame].Transition;
	return D3DXVECTOR2(scale.x * trans.x, scale.y * trans.y);

}

void Unit::InitializationData()
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
		mData.clear();
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
				framePointer = &mData[stateIndex][stoi(mFrame.key())];
				*framePointer = Frame{ rectSize, transition };
				for (json::iterator it = jsonFrameLine.begin(); it != jsonFrameLine.end(); ++it) {
					framePointer->FrameLine[
						it.key() == "?" ?
							0 :
							stoi(it.key())
					] = (int)it.value();
				}
			}
			stateIndex++;
		}
	}
	catch (exception e) {
		// throw "Lỗi khi cố gắng đọc file Json";
		mData.clear();
	}
	return;
}

string Unit::NameToImagePath(string name)
{
	return "Resources/Sprite/" + name + "/" + name + ".png";
}

