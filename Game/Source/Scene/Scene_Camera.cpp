#include "Scene_Camera.h"

void Scene_Camera::operator=(V2 pDelta) {
	Vector_Easing::operator=(pDelta);
}

RECT Scene_Camera::GetSourceRect() {
	return RECT{
		(LONG)(x()),
		(LONG)(y()),
		(LONG)(x() + WIDTH),
		(LONG)(y() + HEIGHT)
	};
}
