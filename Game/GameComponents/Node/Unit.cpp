#include "Unit.h"

Unit::Unit(string name, D3DCOLOR color): Sprite(name, color){
	mState = 1;
	mFrame = 1;
	mPreviousFrame = 0;
	string path_ = "Resources/Sprite/" + mName + "/" + mName + ".png";
	const char * path = path_.c_str();

	Sprite::Sprite(path, color);

	this->SetRect(
		GetRect(mState, mFrame)
	);
	this->mName = mName;
	InitializationData(mName);
}
void Unit::NextFrame()
{
}
