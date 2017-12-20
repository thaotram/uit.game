#pragma once
#include "Object_Map_JafarPalace_Back.h"
#include "../Scene/Scene.h"

Object_Map_JafarPalace_Back::Object_Map_JafarPalace_Back()
    : Object_Map("JafarPalace_Back") {
    mAnimation.Set("back", 1);
}

void Object_Map_JafarPalace_Back::ObjectUpdateEvent(float delay) {}