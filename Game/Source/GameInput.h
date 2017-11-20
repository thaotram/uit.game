#pragma once
#include <map>
using namespace std;

class GameInput
{
private:
	static map<int, bool> mKey;
public:
	GameInput() {};
	~GameInput() {};

	static void SetKeyCode(int pKeyCode, bool pFlag);
	static bool GetKeyCode(int pKeyCode);
};

