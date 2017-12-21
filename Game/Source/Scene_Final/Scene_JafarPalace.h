#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <math.h>
#include <vector>

#include "../GameDebug.h"
#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"

#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"

#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"

#include "../../Define.h"

using namespace std;

class Scene_JafarPalace final : public Scene {
public:
	Scene_JafarPalace();
	~Scene_JafarPalace() {};
};
