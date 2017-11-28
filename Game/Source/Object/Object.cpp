#include "Object.h"
#include "../Scene/Scene.h"

Object::Object(string pName) : mName(pName) {
	mAutoNextFrame = true;
	mSpriteHandler = GameGlobal::GetSpriteHandler();
	mScale = GameGlobal::GetScale();

	mJson = Object_Json::GetJson(mName);
	mTexture = Object_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.01f;
}
void Object::UnitRender(float delay) {
	if (mAutoNextFrame) {
		if (mCurrentTime >= mTimePerFrame) {
			mCurrentTime -= mTimePerFrame;
			mAnimation.NextFrame(this);
		}
		else mCurrentTime += delay;
	}
	
	mSourceRect.Update(this);
	mTransform.Update(this);	
	this->UnitDraw(mTransform, mSourceRect, mPosition);
}
void Object::UnitDraw(Object_Transform pTransform, Object_SourceRect pSourceRect, Object_Vector2 pPosition)
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