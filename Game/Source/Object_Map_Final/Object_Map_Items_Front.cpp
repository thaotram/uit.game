#pragma once
#include "Object_Map_Items_Front.h"
#include "../Scene/Scene.h"

Object_Map_Items_Front::Object_Map_Items_Front()
	: Object_Map("Item") {
	mAnimation.Set("guide", 1);
}

void Object_Map_Items_Front::ObjectUpdateEvent(float delay) {}