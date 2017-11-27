#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Unit_Vector2 : public D3DXVECTOR2 {
public:
	Unit_Vector2() :D3DXVECTOR2(0, 0) {};
	Unit_Vector2(float x, float y) :D3DXVECTOR2(x, y) {};
	Unit_Vector2 operator* (const D3DXVECTOR2& v) const;
	Unit_Vector2 operator* (const float v) const;
	Unit_Vector2 operator+ (const Unit_Vector2& v) const;
	Unit_Vector2 operator+ (const D3DXVECTOR2& v) const;
	Unit_Vector2 operator- (const Unit_Vector2& v) const;
	Unit_Vector2 operator- (const D3DXVECTOR2& v) const;
	D3DXVECTOR2 VECTOR2();
	D3DXVECTOR3 VECTOR3();
	RECT BOUND(const D3DXVECTOR2& v);
};
