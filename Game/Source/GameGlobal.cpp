#include "GameGlobal.h"

GameGlobal::GameGlobal() {}
GameGlobal::~GameGlobal() {}

map<int, int> GameGlobal::InputMap = {
	{VK_LEFT, LEFT},
	{VK_UP, UP},
	{VK_RIGHT, RIGHT},
	{VK_DOWN, DOWN},
	{'Z', CHAR_Z},
	{'X', CHAR_X},
	{'C', CHAR_C}
};
HWND GameGlobal::mHwnd = NULL;
HINSTANCE GameGlobal::mHInstance = NULL;
LPD3DXSPRITE GameGlobal::mSpriteHandler = NULL;
LPDIRECT3DDEVICE9 GameGlobal::mDevice = nullptr;
bool GameGlobal::isGameRunning = true;

bitset<8> GameGlobal::Input = 0;
bitset<8> GameGlobal::InputReal = 0;

void GameGlobal::SetHWND(HWND hwnd) {
	mHwnd = hwnd;
}
void GameGlobal::SetHINSTACE(HINSTANCE instance) {
	mHInstance = instance;
}
void GameGlobal::SetSpriteHandler(LPD3DXSPRITE spriteHandler) {
	mSpriteHandler = spriteHandler;
}
void GameGlobal::SetDevice(LPDIRECT3DDEVICE9 device) {
	mDevice = device;
}

HINSTANCE GameGlobal::GetHINSTACE() {
	return mHInstance;
}
HWND GameGlobal::GetHWND() {
	return mHwnd;
}
LPD3DXSPRITE GameGlobal::GetSpriteHandler() {
	return mSpriteHandler;
}
LPDIRECT3DDEVICE9 GameGlobal::GetDevice() {
	return mDevice;
}