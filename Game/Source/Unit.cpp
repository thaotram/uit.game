#include "Unit.h"
#include "Scene.h"

Unit::Unit(string pName) : mName(pName) {
	mAutoNextFrame = false;
	mSpriteHandler = GameGlobal::GetSpriteHandler();
	mScale = GameGlobal::GetScale();

	mJson = Unit_Json::GetJson(mName);
	mTexture = Unit_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.01f;
}
void Unit::UnitRender(float delay) {
	UnitUpdateBeforeNextFrame();

	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if (mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;

	mSourceRect.Update(this);
	mTransform.Update(this);

	this->UnitDraw(mTransform, mSourceRect, mPosition);
}

void Unit::UnitDraw(Unit_Transform pTransform, Unit_SourceRect pSourceRect, Unit_Vector2 pPosition)
{
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition * mScale).VECTOR3(),
		0xFFFFFFFF
	);
}