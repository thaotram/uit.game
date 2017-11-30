#pragma once
#include "../Utility/Vector_Easing.h"
#include "../../Define.h"

class Scene_Camera : public Vector_Easing {
public:
	Scene_Camera() {};
	Scene_Camera(float x, float y) {
		mSelf = { x, y };
	};
	~Scene_Camera() {};

	RECT GetSourceRect(float delay);
};
