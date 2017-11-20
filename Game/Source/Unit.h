#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

#include "Unit_Json.h"
#include "Unit_Texture.h"
#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"

class VECTOR2 : public D3DXVECTOR2 {
public:
	VECTOR2() {};
	VECTOR2(float x, float y) :D3DXVECTOR2(x, y) {};
	D3DXVECTOR2 operator * (CONST D3DXVECTOR2& v) const {
		return D3DXVECTOR2(x * v.x, y * v.y);
	};
	D3DXVECTOR3 V3(float pScale) {
		return D3DXVECTOR3(x, y, 0) * pScale;
	};
};

typedef VECTOR2 UNIT_POSITION;

class Entity {
private:
	UNIT_ANIMATION					mAnimation;
	UNIT_TRANSFORM					mTransform;
	UNIT_SOURCERECT					mSourceRect;
	UNIT_POSITION					mPosition;
public:
	void Draw() {
	}
};

class Unit
{
protected:
	string							mName;
	LPD3DXSPRITE					mSpriteHandler;
	UNIT_JSON						mJson;
	UNIT_TEXTURE					mTexture;

	UNIT_ANIMATION					mAnimation;
	UNIT_TRANSFORM					mTransform;
	UNIT_SOURCERECT					mSourceRect;
	UNIT_POSITION					mPosition;

	float							mCurrentTime;	//	Thời gian hiện tại
	float 							mTimePerFrame;
protected:
	virtual bool UpdateSprite() { return false; };
	virtual bool DrawSprite() { return false; };
public:
	Unit(string pName);
	~Unit() {};

	void Update(float dt);
	void Draw();
	void Draw(
		UNIT_TRANSFORM pTransform,
		UNIT_SOURCERECT pSourceRect,
		VECTOR2 pPosition
	);

	RECT GetSourceRect();
	VECTOR2 GetPosition();
	UNIT_JSON	   * GetJson();
	UNIT_ANIMATION * GetAnimation();
	UNIT_TRANSFORM * GetTransform();
	void SetPosition(float x, float y);
	RECT GetBound();
};