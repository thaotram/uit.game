#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "Unit_Animation.h"
#include "Unit.h"
#include "GameGlobal.h"
#include "GameDebug.h"

using namespace std;

class Texture {
public:
	static LPDIRECT3DTEXTURE9 Get(string filePath);;
};

typedef Texture UNIT_TEXTURE;