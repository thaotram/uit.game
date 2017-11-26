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
	float pScaling = GameGlobal::GetScale();
	Unit_Vector2 pFlip = { mFlip ? -1.f : 1.f, 1.f };

	Unit_Json * pJson = pUnit->GetJson();
	Unit_Animation * pAnimation = pUnit->GetAnimation();

	D3DXVECTOR2 pBasePoint = pJson->GetBasePoint(pUnit);
	D3DXVECTOR2 pTransition = pJson->GetTransition(pUnit);
	D3DXVECTOR2	* pPosition = pUnit->GetPosition();

	D3DXMatrixTransformation2D(
		this,											//		 D3DXMATRIX	 * pOut
		&(*pPosition * pScaling + pBasePoint),			// const D3DXVECTOR2 * pScalingCenter
		NULL,											//		 FLOAT		 ScalingRotation
		&(pScaling  * pFlip),							// const D3DXVECTOR2 * pScaling
		NULL,											// const D3DXVECTOR2 * pRotationCenter
		NULL,											//		 FLOAT		 Rotation
		&(pFlip * pTransition * pScaling - pBasePoint)	// const D3DXVECTOR2 * pTranslation
	);
}

void Unit_Transform::SetFlip(bool pFlip) {
	mFlip = pFlip;
}
