#include "GameInput.h"

map<int,bool> GameInput::mKey;

void GameInput::SetKeyCode(int pKeyCode, bool pFlag) {
	map<int, bool>::iterator it = mKey.find(pKeyCode);
	if (it != mKey.end()) {
		it->second = pFlag;
	}
	else {
		mKey.insert(make_pair(pKeyCode, pFlag));
	}
}

bool GameInput::GetKeyCode(int pKeyCode) {
	map<int, bool>::iterator it = mKey.find(pKeyCode);
	return it == mKey.end() ? false : it->second;
}
