#include "Scene_Camera.h"

RECT Scene_Camera::GetSourceRect() {
	return RECT{
		(LONG)(x()),
		(LONG)(y()),
		(LONG)(x() + WIDTH),
		(LONG)(y() + HEIGHT)
	};
}
