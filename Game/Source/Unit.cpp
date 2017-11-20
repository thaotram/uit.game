#include "Unit.h"

Unit::Unit(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();
	mTexture.Initialization("Resources/" + mName + ".png");

	mCurrentTime = 0;
	mTimePerFrame = 0.16f;
	mPosition = { 0, 0 };
	mCenter = { 0, 0, 0 };

	mAnimation.Initialization("Resources/" + mName + ".json");
	Update(0);
}
void Unit::Update(float dt) {
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;

		if (UpdateSprite()) return;

		mAnimation++;
		mSourceRect << this;
		mTransform << this;
	}
	else mCurrentTime += dt;
}
void Unit::Draw() {
	if (DrawSprite()) return;
	Draw(mTransform, mSourceRect, mPosition);
}

void Unit::Draw(UNIT_TRANSFORM pTransform, UNIT_SOURCERECT pSourceRect, VECTOR2 pPosition)
{
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&mTexture,
		&pSourceRect,
		&mCenter,
		&pPosition.V3(GameGlobal::GetScale()),
		0xFFFFFFFF
	);
}

RECT Unit::GetSourceRect() {
	return mSourceRect;
}
VECTOR2 Unit::GetPosition() {
	return mPosition;
}

UNIT_ANIMATION * Unit::GetAnimation() {
	return &mAnimation;
}
UNIT_TRANSFORM * Unit::GetTransform() {
	return &mTransform;
}

void Unit::SetPosition(float x, float y) {
	mPosition = { x, y };
}
RECT Unit::GetBound() {
	return RECT{
		(LONG)(mPosition.x),
		(LONG)(mPosition.y),
		(LONG)(mPosition.x + mSourceRect.GetWidth()),
		(LONG)(mPosition.y + mSourceRect.GetHeight())
	};
}
