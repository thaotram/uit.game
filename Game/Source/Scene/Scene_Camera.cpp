#include "Scene_Camera.h"

RECT Scene_Camera::GetSourceRect(float delay) {
	auto v = this->VECTOR2(delay);
	return RECT{
		(LONG)(v.x),
		(LONG)(v.y),
		(LONG)(v.x + WIDTH),
		(LONG)(v.y + HEIGHT)
	};
}
