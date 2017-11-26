#pragma once
#include "Unit_Transform.h"
#include "Unit.h"

Unit_Transform::Unit_Transform() {
	D3DXMatrixTransformation2D(
		this, NULL, NULL, NULL, NULL, NULL, NULL
	);
	mFlip = false;
}

void Unit_Transform::Update(Unit * pUnit) {
	float pScalingFloat = GameGlobal::GetScale();
	Unit_Vector2 pFlip = { mFlip ? -1.f : 1.f, 1.f };

	Unit_Json		* pJson = pUnit->GetJson();
	D3DXVECTOR2		* pPosition = pUnit->GetPosition();

	D3DXVECTOR2 pBasePoint = pJson->GetBasePoint(pUnit);
	D3DXVECTOR2 pFrameTransition = pJson->GetTransition(pUnit);

	D3DXVECTOR2 pScalingCenter = *pPosition * pScalingFloat + pBasePoint;
	D3DXVECTOR2 pTransition = (pFlip * pFrameTransition * pScalingFloat - pBasePoint).VECTOR2();
	D3DXVECTOR2 pScaling = pScalingFloat  * pFlip;

	D3DXMatrixTransformation2D(
		this,				//		 D3DXMATRIX	 * pOut
		&pScalingCenter,	// const D3DXVECTOR2 * pScalingCenter
		NULL,				//		 FLOAT		   ScalingRotation
		&pScaling,			// const D3DXVECTOR2 * pScalingFloat
		NULL,				// const D3DXVECTOR2 * pRotationCenter
		NULL,				//		 FLOAT		   Rotation
		&pTransition		// const D3DXVECTOR2 * pTranslation
	);
}

void Unit_Transform::SetFlip(bool pFlip) {
	mFlip = pFlip;
}