#pragma once
#include <iostream>
#include <sstream>
#include <d3d9.h>
#include <d3dx9.h>
#include "GameGlobal.h"

using namespace std;

class GameDebug {
private:

public:
	static void Log(string input);
	static void Title(float input);
	static void Title(RECT input);
	static void Title(string input);
	static void Draw(RECT pRect, D3DCOLOR pColor = 0xffff0000);
	static void DrawHL(LONG pTop, LONG pWeight, D3DCOLOR pColor = 0xffff0000);
	static void DrawVL(LONG pLeft, LONG pWeight, D3DCOLOR pColor = 0xffff0000);
};