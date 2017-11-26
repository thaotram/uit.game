#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <utility>
#include <iostream>

using namespace std;

class Unit;
class Unit_Entity;

class Unit_SourceRect : public RECT {
public:
	// Lấy thông tin cho SourceRect từ
	// + Unit_Animation > Frame {mState, mFrameIndex}
	void Update(Unit * pUnit);
	void operator=(RECT pRect);

	LONG GetWidth() {
		return right - left;
	}
	LONG GetHeight() {
		return bottom - top;
	}
};

