#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#include "GameGlobal.h"

using namespace std;

class Unit_Texture {
private:
	static map<string, Unit_Texture*> Unit_Textures;
	LPDIRECT3DTEXTURE9 mSelf;
	Unit_Texture(string pName);
public:
	static Unit_Texture * GetTexture(string pName);
	LPDIRECT3DTEXTURE9 operator&();
};