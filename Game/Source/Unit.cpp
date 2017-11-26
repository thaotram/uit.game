#include "Unit.h"

Unit::Unit(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();

	mJson = Unit_Json::GetJson(mName);
	mTexture = Unit_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.08f;
}
void Unit::Update(float dt) {
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;

		if (UpdateUnit()) return;

		mAnimation.NextFrame(this);
		mSourceRect.Update(this);
		mTransform.Update(this);
	}
	else mCurrentTime += dt;
}
void Unit::Draw() {
	if (DrawUnit()) return;
	this->Draw(mTransform, mSourceRect, mPosition);
}

void Unit::Draw(Unit_Transform pTransform, Unit_SourceRect pSourceRect, Unit_Vector2 pPosition)
{
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition.V3() * GameGlobal::GetScale()),
		0xFFFFFFFF
	);
}

Unit_Json * Unit::GetJson()
{
	return mJson;
}
