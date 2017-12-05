#include "Object.h"
#include "../Scene/Scene.h"
#include "../../Define.h"

Object::Object(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();

	mJson = Object_Json::GetJson(mName);
	mTexture = Object_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.05f;
}
void Object::ObjectRender(float delay) {
	mJson = Object_Json::GetJson(mName);

	ObjectUpdateProperties(delay);
	ObjectDraw(mTransform, mSourceRect, mPosition);
}
void Object::ObjectDraw(Object_Transform pTransform, Object_SourceRect pSourceRect, Vector_Easing pPosition) {
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition.VECTOR() * SCALE).VECTOR3(),
		0xFFFFFFFF
	);
}