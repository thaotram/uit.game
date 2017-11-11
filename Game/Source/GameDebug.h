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
	static void Log(string input) {
		wstring wstring;
		wstringstream wstringstream;
		wstring.assign(input.begin(), input.end());
		wstringstream << wstring << L"\n";

		// LPCWSTR
		OutputDebugString(
			wstringstream.str().c_str()
		);
	}
	static void Title(string input) {
		wstring wstring;
		wstring.assign(input.begin(), input.end());
		SetWindowText(
			GameGlobal::GetHWND(),
			wstring.c_str()
		);
	}
	static void Draw(RECT pRect, D3DCOLOR pColor = 0xffff0000) {
		LPDIRECT3DDEVICE9 device = GameGlobal::GetDevice();
		LPDIRECT3DSURFACE9 backBuffer = NULL;
		LPDIRECT3DSURFACE9	  surface = NULL;;
		device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_LEFT, &backBuffer);
		device->CreateOffscreenPlainSurface(
			1, 1, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &surface, NULL
		);
		device->ColorFill(surface, NULL, pColor);

		device->StretchRect(
			surface,			// from
			NULL,				// which portion?
			backBuffer,			// to
			&pRect,				// which portion?
			D3DTEXF_NONE
		);
	}
	static void DrawHL(LONG pTop, LONG pWeight, D3DCOLOR pColor = 0xffff0000) {
		Draw(RECT{
			0,
			pTop,
			GameGlobal::GetWidth(),
			pTop + pWeight
		}, pColor);
	}
	static void DrawVL(LONG pLeft, LONG pWeight, D3DCOLOR pColor = 0xffff0000) {
		Draw(RECT{
			pLeft,
			0,
			pLeft + pWeight,
			GameGlobal::GetHeight()
		}, pColor);
	}
};