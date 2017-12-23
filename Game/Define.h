#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <windows.h>

#define APP_CLASS L"Game"
#define MAIN_WINDOW_TITLE L"Game Title"

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

bool isIntersect(RECT a, RECT b);

#define intersect_function
#endif