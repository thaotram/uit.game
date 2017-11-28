#pragma once
#include "Object_Transform.h"
#include "Object.h"

Object_Transform::Object_Transform() {
	D3DXMatrixTransformation2D(
		this, NULL, NULL, NULL, NULL, NULL, NULL
	);
	mFlip = false;
}

void Object_Transform::Update(Object * pObject) {
	float pScalingFloat = GameGlobal::GetScale();
	Object_Vector2 pFlip = { mFlip ? -1.f : 1.f, 1.f };

	Object_Json		* pJson = pObject->GetJson();
	D3DXVECTOR2		* pPosition = pObject->GetPosition();

	D3DXVECTOR2 pBasePoint = pJson->GetBasePoint(pObject);
	D3DXVECTOR2 pFrameTransition = pJson->GetTransition(pObject);

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

void Object_Transform::SetFlip(bool pFlip) {
	mFlip = pFlip;
}