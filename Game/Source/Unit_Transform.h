//#ifndef _Transform_H
//#define _Transform_H

#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#include "GameGlobal.h"
class Transform : public D3DXMATRIX {
private:
	bool                    mIsFlipVertical;	// Lật theo chiều dọc
	bool					mIsFlipHorizontal;	// Lật theo chiều ngang

	D3DXVECTOR2             mScaling;			// Vector tùy chỉnh độ phóng to / thu nhỏ của texture
	D3DXVECTOR2             mTranslation;		// Vector tịnh tiến hình ảnh
public:
	Transform() {
		D3DXMatrixTransformation2D(
			this, NULL, NULL, NULL, NULL, NULL, NULL
		);
		mIsFlipVertical = false;
		mIsFlipHorizontal = false;

		mScaling = {
			GameGlobal::GetScale(),GameGlobal::GetScale()
		};
		mTranslation = { 0,0 };
	}
	void UpdateFrom(RECT pSourceRect, D3DXVECTOR3 pPosition, D3DXVECTOR2 pTransition) {
		D3DXVECTOR2 pScalingCenter = D3DXVECTOR2(
			pPosition.x, // + (pSourceRect.right - pSourceRect.left) / 2,
			pPosition.y  // + (pSourceRect.bottom - pSourceRect.top) / 2
		);
		D3DXVECTOR2 pScaling = D3DXVECTOR2(
			mScaling.x * (mIsFlipHorizontal ? -1 : 1),	// Chiều ngang
			mScaling.y * (mIsFlipVertical ? -1 : 1)		// Chiều dọc
		);

		mTranslation = {
			mScaling.x * pTransition.x,
			mScaling.y * pTransition.y
		};

		D3DXMatrixTransformation2D(
			this,					//		 D3DXMATRIX	 * pOut
			&pScalingCenter,		// const D3DXVECTOR2 * pScalingCenter
			NULL,					//		 FLOAT		 ScalingRotation
			&pScaling,				// const D3DXVECTOR2 * pScaling
			NULL,					// const D3DXVECTOR2 * pRotationCenter
			NULL,					//		 FLOAT		 Rotation
			&mTranslation			// const D3DXVECTOR2 * pTranslation
		);
	}

	// True = Lật, False = Giữ nguyên
	// Horizontal = Lật ngang, Vertical = Lật dọc
	void SetFlip(bool pHorizontal, bool pVertical) {
		mIsFlipHorizontal = pHorizontal;
		mIsFlipVertical = pVertical;
	}
	void SetScale(float pScale) {
		mScaling = { pScale, pScale };
	}
};

typedef Transform UNIT_TRANSFORM;

//#endif // !_Transform_H
