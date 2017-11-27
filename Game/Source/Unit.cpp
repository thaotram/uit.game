#include "Unit.h"
#include "Scene.h"

Unit::Unit(string pName) : mName(pName) {
	mAutoNextFrame = false;
	mSpriteHandler = GameGlobal::GetSpriteHandler();

	mJson = Unit_Json::GetJson(mName);
	mTexture = Unit_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.01f;
}
void Unit::UnitRender(float delay) {
	SelfUpdateBeforeNextFrame();

	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if (mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;

	mSourceRect.Update(this);
	mTransform.Update(this);
	this->UnitRenderWithParameter(mTransform, mSourceRect, mPosition);
}

void Unit::UnitRenderWithParameter(Unit_Transform pTransform, Unit_SourceRect pSourceRect, Unit_Vector2 pPosition)
{
	float pScale = GameGlobal::GetScale();

	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition * pScale).VECTOR3(),
		0xFFFFFFFF
	);
}