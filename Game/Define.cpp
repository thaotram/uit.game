#include "Define.h"

bool isIntersect(RECT a, RECT b) {
	return
		a.left < b.right &&
		a.right > b.left &&
		a.top <= b.bottom &&
		a.bottom >= b.top;
}

LPCWSTR StringToLPCWSTR(string input) {
	wstring wstring;
	wstringstream wstringstream;
	wstring.assign(input.begin(), input.end());
	wstringstream << wstring << L"\n";
	return wstringstream.str().c_str();
}