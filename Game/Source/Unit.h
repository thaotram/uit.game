#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

#include "Unit_Texture.h"
#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"


class Unit
{
private:
	string							mName;
	LPD3DXSPRITE					mSpriteHandler;
	LPDIRECT3DTEXTURE9				mTexture;
	UNIT_ANIMATION					mAnimation;
	UNIT_TRANSFORM					mTransform;
	RECT							mSourceRect;

	D3DXVECTOR3						mCenter;
	D3DXVECTOR3						mPosition;

	float mCurrentTime, mTimePerFrame;
public:
	Unit(string pName) : mName(pName) {
		mSpriteHandler = GameGlobal::GetSpriteHandler();
		mTexture = UNIT_TEXTURE::Get("Resources/" + mName + ".png");

		mPosition = { 200,200,0 };
		mTransform.SetScale(4);
		mTimePerFrame = 0.2f;
		Update(0);
	};
	~Unit() {};

	void Update(float dt) {
		if (mAnimation.empty()) {
			mAnimation.Initialization("Resources/" + mName + ".json");
		}
		if (mCurrentTime >= mTimePerFrame) {
			mAnimation.Initialization("Resources/" + mName + ".json");
			mAnimation.Log();
			mCurrentTime = 0;
			//!? Thao tác cập nhật frame - BEGIN

			mAnimation.NextFrame();
			mSourceRect = mAnimation.GetFrame();
			mTransform.UpdateFrom(mSourceRect, mPosition, mAnimation.GetTransition());

			//!? Thao tác cập nhật frame - END
		}
		else mCurrentTime += dt;
	}

	void Draw() {
		mSpriteHandler->SetTransform(&mTransform);
		mSpriteHandler->Draw(
			mTexture,
			&mSourceRect,
			&mCenter,
			&mPosition,
			0xFFFFFFFF
		);
	}
	RECT GetSourceRect() {
		return mSourceRect;
	}
	D3DXVECTOR3 GetPosition() {
		return mPosition;
	}
	UNIT_ANIMATION GetAnimation() {
		return mAnimation;
	}
};