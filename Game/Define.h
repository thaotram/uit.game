#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <windows.h>
#include <iostream>
#include <sstream>

#define APP_CLASS L"Aladdin: 15520649 - 15520914 - 15520325"
#define MAIN_WINDOW_TITLE L"Aladdin: 15520649 - 15520914 - 15520325"

#define WIDTH 320
#define HEIGHT 224
#define SCALE 3
#define FPS 60
#define BACKGROUND_COLOR 0xff000000

#define MAP_HEIGHT 686
#define MAP_WIDTH 4771

#define unitHeight 87
#define unitWidth 30

#define V2 D3DXVECTOR2

using namespace std;

enum {
	ANYBUTTON,
	LEFT,
	UP,
	RIGHT,
	DOWN,
	CHAR_Z,
	CHAR_X,
	CHAR_C
};

#ifndef intersect_function
#define intersect_function
bool isIntersect(RECT a, RECT b);
#endif // !intersect_function

#ifndef StringToLPCWSTR_function
#define StringToLPCWSTR_function
LPCWSTR StringToLPCWSTR(string input);
#endif // !StringToLPCWSTR_function
