#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include "Unit_Vector2.h"

class Unit;
class Unit_Entity;

class Unit_Transform: public D3DXMATRIX {
private:
	bool mFlip;	// Flip
public:
	Unit_Transform();

	// Lấy thông tin Transform từ
	// + Json
	// + Position
	void Update(Unit * pUnit);
	void SetFlip(bool pFlip);
};
