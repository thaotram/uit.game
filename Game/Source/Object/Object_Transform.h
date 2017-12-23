#ifndef Object_Transform_Included
#define Object_Transform_Included

#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include "../Utility/Vector.h"
#include "../../Define.h"

enum Flip {
	Left, 
	Right,
	Stand
};

//class Object;
class Object_Transform: public D3DXMATRIX {
private:
	bool mFlip;	// Flip
public:
	Object_Transform();

	void Update(Object * pObject);	// Lấy thông tin Transform từ: Json, Position
	void SetFlip(Flip pFlip);
	void SetFlip(bool pIsFlip);
	bool GetFlip();
};

#endif