#pragma once
#include "Object_Map_JafarPalace_Front.h"
#include "../Scene/Scene.h"

Object_Map_JafarPalace_Front::Object_Map_JafarPalace_Front()
    : Object_Map("JafarPalace_Front") {
    mAnimation.Set("back", 1);
}

void Object_Map_JafarPalace_Front::ObjectUpdateEvent(float delay) {};