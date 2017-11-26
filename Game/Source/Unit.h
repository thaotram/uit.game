#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

#include "Unit_Json.h"
#include "Unit_Texture.h"
#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"

class Unit
{
protected:
	string				mName;
	LPD3DXSPRITE		mSpriteHandler;
	Unit_Json			* mJson;
	Unit_Texture		* mTexture;

	Unit_Vector2		mPosition;
	Unit_Animation		mAnimation;
	Unit_Transform		mTransform;
	Unit_SourceRect		mSourceRect;

	float				mCurrentTime;
	float 				mTimePerFrame;
protected:
	virtual bool AutoNextFrame() { return false; };
	virtual bool DrawUnit() { return false; };		//? Tạm thời bỏ qua hàm này
	/* Đoạn này viết còn tệ, còn nhập nhằng khi gọi làm AutoNextFrame... */
public:
	Unit(string pName);
	~Unit() {};

	void Update(float dt);
	void Draw();
	void Draw(
		Unit_Transform pTransform,
		Unit_SourceRect pSourceRect,
		Unit_Vector2 pPosition
	);

	Unit_SourceRect * GetSourceRect() {
		return &mSourceRect;
	}
	Unit_Vector2 * GetPosition() {
		return &mPosition;
	}
	Unit_Animation * GetAnimation() {
		return &mAnimation;
	}
	Unit_Transform * GetTransform() {
		return &mTransform;
	}
	Unit_Json * GetJson() {
		return mJson;
	}
};