#include "Unit.h"

Unit::Unit(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();
	mJson << mName;
	mTexture << mName;

	mCurrentTime = 0;
	mTimePerFrame = 0.16f;
}
void Unit::Update(float dt) {
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if (UpdateSprite()) return;
		mEntity.Update(this);
	}
	else mCurrentTime += dt;
}
void Unit::Draw() {
	if (DrawSprite()) return;
	mEntity.Draw(this);
}

void Unit::Draw(Unit_Transform pTransform, Unit_SourceRect pSourceRect, Unit_Vector2 pPosition)
{
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&mTexture,
		&pSourceRect,
		NULL,
		&(pPosition.V3() * GameGlobal::GetScale()),
		0xFFFFFFFF
	);
}

Unit_Json * Unit::GetJson()
{
	return &mJson;
}
