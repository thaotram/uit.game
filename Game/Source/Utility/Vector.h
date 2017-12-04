#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Vector : public D3DXVECTOR2 {
public:
	Vector() :D3DXVECTOR2(0, 0) {};
	Vector(D3DXVECTOR2 v) :D3DXVECTOR2(v) {};
	Vector(float x, float y) :D3DXVECTOR2(x, y) {};
	Vector operator* (const D3DXVECTOR2& v) const;
	Vector operator* (const float v) const;
	Vector operator+ (const Vector& v) const;
	Vector operator+ (const D3DXVECTOR2& v) const;
	Vector operator- (const Vector& v) const;
	Vector operator- (const D3DXVECTOR2& v) const;
	D3DXVECTOR2 VECTOR2();
	D3DXVECTOR3 VECTOR3();

	RECT RECT(D3DXVECTOR2 v) {
		return {
			(LONG)(x),
			(LONG)(y),
			(LONG)(x + v.x),
			(LONG)(y + v.y)
		};
	}
};
