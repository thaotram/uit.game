#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#include "GameGlobal.h"
#include "Unit_Animation.h"

class VECTOR2 : public D3DXVECTOR2 {
public:
	VECTOR2(pair<bool, bool> f) :D3DXVECTOR2(
		(float)(f.first ? -1 : 1),
		(float)(f.second ? -1 : 1)
	) {}
	D3DXVECTOR2 operator * (CONST D3DXVECTOR2& v) const {
		return D3DXVECTOR2(x * v.x, y * v.y);
	}
};

class Transform : public D3DXMATRIX {
private:
	pair<bool, bool>		mFlip;				// Flip

	float					mScaling;			// Vector tùy chỉnh độ phóng to / thu nhỏ của texture
	D3DXVECTOR2             mTranslation;		// Vector tịnh tiến hình ảnh
public:
	Transform() {
		D3DXMatrixTransformation2D(
			this, NULL, NULL, NULL, NULL, NULL, NULL
		);
		mFlip = make_pair(false, false);

		mScaling = GameGlobal::GetScale();
		mTranslation = { 0,0 };
	}
	void UpdateFrom(D3DXVECTOR2 pPosition, UNIT_ANIMATION pAnimation) {
		VECTOR2 pFlip(mFlip);
		D3DXVECTOR2 pBasePoint = pAnimation.GetBasePoint();
		D3DXVECTOR2 pTransition = pAnimation.GetTransition();
		D3DXVECTOR2 pScalingCenter = pPosition + pBasePoint;
		D3DXVECTOR2 pScaling = mScaling * pFlip;

		mTranslation = pFlip * pTransition * mScaling - pBasePoint;

		D3DXMatrixTransformation2D(
			this,								//		 D3DXMATRIX	 * pOut
			&pScalingCenter,					// const D3DXVECTOR2 * pScalingCenter
			NULL,								//		 FLOAT		 ScalingRotation
			&pScaling,							// const D3DXVECTOR2 * pScaling
			NULL,								// const D3DXVECTOR2 * pRotationCenter
			NULL,								//		 FLOAT		 Rotation
			&mTranslation						// const D3DXVECTOR2 * pTranslation
		);
	}
	void SetFlip(bool pFlip) {
		// mFlipH = pFlip;
	}
};

typedef Transform UNIT_TRANSFORM;