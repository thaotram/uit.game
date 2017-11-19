#include "Unit_Transform.h"
#include "Unit.h"

Transform::Transform() {
	D3DXMatrixTransformation2D(
		this, NULL, NULL, NULL, NULL, NULL, NULL
	);
	mFlip = false;
}

void Transform::operator<<(Unit * pParent){
	float pScaling = GameGlobal::GetScale();
	VECTOR2 pFlip(mFlip);
	D3DXVECTOR2 pBasePoint = pParent->GetAnimation()->GetBasePoint();
	D3DXVECTOR2 pTransition = pParent->GetAnimation()->GetTransition();
	D3DXVECTOR2 pPosition = pParent->GetPosition();
	D3DXMatrixTransformation2D(
		this,											//		 D3DXMATRIX	 * pOut
		&(pPosition + pBasePoint),						// const D3DXVECTOR2 * pScalingCenter
		NULL,											//		 FLOAT		 ScalingRotation
		&(pScaling  * pFlip),							// const D3DXVECTOR2 * pScaling
		NULL,											// const D3DXVECTOR2 * pRotationCenter
		NULL,											//		 FLOAT		 Rotation
		&(pFlip * pTransition * pScaling - pBasePoint)	// const D3DXVECTOR2 * pTranslation
	);
}

void Transform::SetFlip(bool pFlip) {
	mFlip = pFlip;
}
