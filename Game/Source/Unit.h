#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

#include "Unit_Entity.h"

#include "Unit_Json.h"
#include "Unit_Texture.h"
#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"

class Unit_Entity;

class VECTOR2 : public D3DXVECTOR2 {
public:
	VECTOR2() :D3DXVECTOR2(0, 0) {};
	VECTOR2(float x, float y) :D3DXVECTOR2(x, y) {};
	D3DXVECTOR2 operator * (CONST D3DXVECTOR2& v) const {
		return D3DXVECTOR2(x * v.x, y * v.y);
	};
	D3DXVECTOR3 V3(float pScale) {
		return D3DXVECTOR3(x, y, 0) * pScale;
	};
	D3DXVECTOR2 V2() {
		return D3DXVECTOR2(x, y);
	};
};

class Unit
{
protected:
	string							mName;
	LPD3DXSPRITE					mSpriteHandler;
	Unit_Json						mJson;
	Unit_Texture					mTexture;

	Unit_Entity						mEntity;

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
		Unit_Transform pTransform,
		Unit_SourceRect pSourceRect,
		D3DXVECTOR2 pPosition
	);

	Unit_Json	   * GetJson();
	//RECT GetSourceRect();
	//VECTOR2 GetPosition();
	//UNIT_ANIMATION * GetAnimation();
	//UNIT_TRANSFORM * GetTransform();
	//void SetPosition(float x, float y);
	//RECT GetBound();
};