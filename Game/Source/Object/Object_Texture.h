#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#include "../GameGlobal.h"

using namespace std;

class Object_Texture {
private:
	static map<string, Object_Texture*> Object_Textures;
	LPDIRECT3DTEXTURE9 mNow;
	Object_Texture(string pName);
public:
	static Object_Texture * GetTexture(string pName);
	LPDIRECT3DTEXTURE9 operator&();
};