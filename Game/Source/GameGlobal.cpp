#include "GameGlobal.h"

GameGlobal::GameGlobal() {}
GameGlobal::~GameGlobal() {}

// Init Value

int GameGlobal::mWidth = 0;
int GameGlobal::mHeight = 0;
float GameGlobal::mFPS = 1;
HWND GameGlobal::mHwnd = NULL;
HINSTANCE GameGlobal::mHInstance = NULL;
LPD3DXSPRITE GameGlobal::mSpriteHandler = NULL;
LPDIRECT3DDEVICE9 GameGlobal::mDevice = nullptr;
D3DCOLOR  GameGlobal::mBackgroundColor = 0xffff00ff;
bool GameGlobal::isGameRunning = true;

void GameGlobal::SetCurrentHWND(HWND hwnd)
{
	mHwnd = hwnd;
}
void GameGlobal::SetCurrentHINSTACE(HINSTANCE instance)
{
	mHInstance = instance;
}
void GameGlobal::SetSpriteHandler(LPD3DXSPRITE spriteHandler)
{
	mSpriteHandler = spriteHandler;
}
void GameGlobal::SetCurrentDevice(LPDIRECT3DDEVICE9 device)
{
	mDevice = device;
}
void GameGlobal::SetBackgroundColor(D3DCOLOR backgroundColor)
{
	mBackgroundColor = backgroundColor;
}

HINSTANCE GameGlobal::GetCurrentHINSTACE()
{
	return mHInstance;
}
HWND GameGlobal::GetCurrentHWND()
{
	return mHwnd;
}
LPD3DXSPRITE GameGlobal::GetSpriteHandler()
{
	return mSpriteHandler;
}
LPDIRECT3DDEVICE9 GameGlobal::GetCurrentDevice()
{
	return mDevice;
}
D3DCOLOR GameGlobal::GetBackgroundColor()
{
	return mBackgroundColor;;
}

void GameGlobal::SetWidth(int width)
{
	mWidth = width;
}
int GameGlobal::GetWidth()
{
	return mWidth;
}
void GameGlobal::SetHeight(int height)
{
	mHeight = height;
}
int GameGlobal::GetHeight()
{
	return mHeight;
}
void GameGlobal::SetFPS(float fps)
{
	mFPS = fps;
}
float GameGlobal::GetFPS()
{
	return mFPS;
}
