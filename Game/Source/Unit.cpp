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
void Unit::Update(float dt) {
	SelfUpdateBeforeNextFrame();

	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if (mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += dt;
}
void Unit::Draw() {
	mSourceRect.Update(this);
	mTransform.Update(this);
	this->DrawWithParameter(mTransform, mSourceRect, mPosition);
}

void Unit::DrawWithParameter(Unit_Transform pTransform, Unit_SourceRect pSourceRect, Unit_Vector2 pPosition)
{
	float pScale = GameGlobal::GetScale();
	Unit_Vector2 pCameraPotition = mScene->mCameraPosition;

	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition * pScale).VECTOR3(),
		0xFFFFFFFF
	);
}