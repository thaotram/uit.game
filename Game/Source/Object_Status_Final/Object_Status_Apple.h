#pragma once
#include "../Object_Status/Object_Status.h"
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Status_Apple final : public Object_Status {
public:
	Object_Status_Apple();
	~Object_Status_Apple() {};

	void ObjectUpdateEvent(float dt) {
		// notthing
	};
};

