#pragma once
#include "Object_Map_JafarPalace_Background.h"
#include "../Scene/Scene.h"

Object_Map_JafarPalace_Background::Object_Map_JafarPalace_Background()
    : Object_Map("JafarPalace_Background") {
    mAnimation.Set("back", 1);
}

void Object_Map_JafarPalace_Background::ObjectUpdateEvent(float delay) {
    
}