
#pragma once
#include "Object_Transform.h"
#include "Object.h"
#include "../../Define.h"

Object_Transform::Object_Transform() {
	D3DXMatrixTransformation2D(
		this, NULL, NULL, NULL, NULL, NULL, NULL
	);
	mFlip = false;
}

void Object_Transform::Update(Object * pObject) {
	Vector pFlip = { mFlip ? -1.f : 1.f, 1.f };

	Object_Json	* pJson = pObject->GetJson();
	D3DXVECTOR2	* pPosition = pObject->GetPosition();

	D3DXVECTOR2 pBasePoint = pJson->GetBasePoint(pObject);
	D3DXVECTOR2 pFrameTransition = pJson->GetTransition(pObject);

	D3DXVECTOR2 pScalingCenter = *pPosition * SCALE + pBasePoint;
	D3DXVECTOR2 pTranslation = (pFlip * pFrameTransition * SCALE - pBasePoint).VECTOR2();
	D3DXVECTOR2 pScaling = SCALE * pFlip;

	D3DXMatrixTransformation2D(
		this,				//		 D3DXMATRIX	 * pOut
		&pScalingCenter,	// const D3DXVECTOR2 * pScalingCenter
		NULL,				//		 FLOAT		   ScalingRotation
		&pScaling,			// const D3DXVECTOR2 * pScalingFloat
		NULL,				// const D3DXVECTOR2 * pRotationCenter
		NULL,				//		 FLOAT		   Rotation
		&pTranslation		// const D3DXVECTOR2 * pTranslation
	);
}

void Object_Transform::SetFlip(bool pFlip) {
	mFlip = pFlip;
}