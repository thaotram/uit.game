#pragma once
#include "Unit_Transform.h"
#include "Unit.h"

UNIT_TRANSFORM::UNIT_TRANSFORM() {
	D3DXMatrixTransformation2D(
		this, NULL, NULL, NULL, NULL, NULL, NULL
	);
	mFlip = false;
}

Unit * UNIT_TRANSFORM::operator<<(Unit * pUnit) {
	float pScaling = GameGlobal::GetScale();
	VECTOR2 pFlip = { mFlip ? -1.f : 1.f, 1.f };
	D3DXVECTOR2 pBasePoint = pUnit->GetAnimation()->GetBasePoint();
	D3DXVECTOR2 pTransition = pUnit->GetAnimation()->GetTransition();
	D3DXVECTOR2 pPosition = pUnit->GetPosition();

	D3DXMatrixTransformation2D(
		this,											//		 D3DXMATRIX	 * pOut
		&(pPosition * pScaling + pBasePoint),			// const D3DXVECTOR2 * pScalingCenter
		NULL,											//		 FLOAT		 ScalingRotation
		&(pScaling  * pFlip),							// const D3DXVECTOR2 * pScaling
		NULL,											// const D3DXVECTOR2 * pRotationCenter
		NULL,											//		 FLOAT		 Rotation
		&(pFlip * pTransition * pScaling - pBasePoint)	// const D3DXVECTOR2 * pTranslation
	);
	return pUnit;
}

void UNIT_TRANSFORM::SetFlip(bool pFlip) {
	mFlip = pFlip;
}
