#include "Unit_Vector2.h"

D3DXVECTOR3 Unit_Vector2::VECTOR3() {
	return D3DXVECTOR3(x, y, 0);
}
D3DXVECTOR2 Unit_Vector2::VECTOR2() {
	return D3DXVECTOR2(x, y);
}

Unit_Vector2 Unit_Vector2::operator*(const float v) const {
	return Unit_Vector2(x * v, y * v);
}
Unit_Vector2 Unit_Vector2::operator*(const D3DXVECTOR2 &v) const {
	return Unit_Vector2(x * v.x, y * v.y);
}
Unit_Vector2 Unit_Vector2::operator-(const Unit_Vector2 &v) const {
	return Unit_Vector2(x - v.x, y - v.y);
}
Unit_Vector2 Unit_Vector2::operator-(const D3DXVECTOR2 &v) const {
	return Unit_Vector2(x - v.x, y - v.y);
}