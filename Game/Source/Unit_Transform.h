#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

class Unit;

class UNIT_TRANSFORM: public D3DXMATRIX {
private:
	bool mFlip;	// Flip
public:
	UNIT_TRANSFORM();

	// Lấy thông tin Transform từ
	// + Animation > BasePoint, Transition {mState, mFrameIndex}
	// + Unit > Position {mPosition}
	// + Transform > Flip {this.mFlip}
	Unit * operator<< (Unit * pUnit);
	void SetFlip(bool pFlip);
};
