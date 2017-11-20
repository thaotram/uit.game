#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#include "GameGlobal.h"

using namespace std;

class Unit_Texture {
private:
	LPDIRECT3DTEXTURE9 mSelf;
public:
	Unit_Texture() {};
	void operator<<(string pName);
	LPDIRECT3DTEXTURE9 operator&();
};