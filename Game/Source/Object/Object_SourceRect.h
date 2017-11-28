#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <utility>
#include <iostream>

using namespace std;

class Object;

class Object_SourceRect : public RECT {
public:
	// Lấy thông tin cho SourceRect từ
	// + Object_Animation > Frame {mState, mFrameIndex}
	void Update(Object * pObject);
	void operator=(RECT pRect);

	LONG GetWidth() {
		return right - left;
	}
	LONG GetHeight() {
		return bottom - top;
	}
};

