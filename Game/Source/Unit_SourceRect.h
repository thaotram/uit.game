#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

class Unit;

class UNIT_SOURCERECT : public RECT {
public:
	// Lấy thông tin cho SourceRect từ
	// + Animation > Frame {mState, mFrameIndex}
	Unit * operator<<(Unit * pUnit);
	void operator=(RECT pRect);

	LONG GetWidth() {
		return right - left;
	}
	LONG GetHeight() {
		return bottom - top;
	}
};

