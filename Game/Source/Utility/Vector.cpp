#include "Vector.h"

D3DXVECTOR3 VECTOR::VECTOR3() {
	return D3DXVECTOR3(x, y, 0);
}
D3DXVECTOR2 VECTOR::VECTOR2() {
	return D3DXVECTOR2(x, y);
}

VECTOR VECTOR::operator*(const float v) const {
	return VECTOR(x * v, y * v);
}
VECTOR VECTOR::operator*(const D3DXVECTOR2 &v) const {
	return VECTOR(x * v.x, y * v.y);
}
VECTOR VECTOR::operator+(const VECTOR &v) const {
	return VECTOR(x + v.x, y + v.y);
}
VECTOR VECTOR::operator+(const D3DXVECTOR2 &v) const {
	return VECTOR(x + v.x, y + v.y);
}
VECTOR VECTOR::operator-(const VECTOR &v) const {
	return VECTOR(x - v.x, y - v.y);
}
VECTOR VECTOR::operator-(const D3DXVECTOR2 &v) const {
	return VECTOR(x - v.x, y - v.y);
}