#include "Vector.h"

D3DXVECTOR3 Vector::VECTOR3() {
	return D3DXVECTOR3(x, y, 0);
}
D3DXVECTOR2 Vector::VECTOR2() {
	return D3DXVECTOR2(x, y);
}

Vector Vector::operator*(const float v) const {
	return Vector(x * v, y * v);
}
Vector Vector::operator*(const D3DXVECTOR2 &v) const {
	return Vector(x * v.x, y * v.y);
}
Vector Vector::operator+(const Vector &v) const {
	return Vector(x + v.x, y + v.y);
}
Vector Vector::operator+(const D3DXVECTOR2 &v) const {
	return Vector(x + v.x, y + v.y);
}
Vector Vector::operator-(const Vector &v) const {
	return Vector(x - v.x, y - v.y);
}
Vector Vector::operator-(const D3DXVECTOR2 &v) const {
	return Vector(x - v.x, y - v.y);
}