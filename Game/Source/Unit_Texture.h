#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#include "GameGlobal.h"

using namespace std;

class Texture {
private:
	LPDIRECT3DTEXTURE9 mSelf;
public:
	Texture() {};
	void Initialization(string filePath);
	LPDIRECT3DTEXTURE9 operator&();
};

typedef Texture UNIT_TEXTURE;