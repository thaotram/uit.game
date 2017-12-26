#pragma once
#include "Object_Map_Scene_Start.h"
#include "../Scene/Scene.h"

Object_Map_Scene_Start::Object_Map_Scene_Start()
	: Object_Map("Option_Scene") {
	mAnimation.Set("main_menu", 1);
}

void Object_Map_Scene_Start::ObjectUpdateEvent(float delay) {

}