#pragma once
#include <iostream>
#include <sstream>
#include <d3d9.h>
#include <d3dx9.h>
#include "GameGlobal.h"

using namespace std;

class GameLog {
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
			GameGlobal::GetCurrentHWND(),
			wstring.c_str()
		);
	}
};