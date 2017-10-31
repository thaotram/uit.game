#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <windows.h>

class GameGlobal
{
private:
	static HWND					mHwnd;				// hwnd hiện tại
	static HINSTANCE			mHInstance;			// hInstance của windows hiện tại
	static LPD3DXSPRITE			mSpriteHandler;		// spriteHanlder hiện tại
	static LPDIRECT3DDEVICE9	mDevice;			// device directX hiện tại
	static int					mWidth, mHeight;	// size của cửa sổ
	static float				mFPS;				// frame per second
public:
	GameGlobal();
	~GameGlobal();

	static bool isGameRunning; //trạng thái xem game có đang chạy khong

	static HWND GetCurrentHWND();
	static HINSTANCE GetCurrentHINSTACE();
	static LPD3DXSPRITE GetCurrentSpriteHandler();
	static LPDIRECT3DDEVICE9 GetCurrentDevice();

	static void SetCurrentHWND(HWND hwnd);
	static void SetCurrentHINSTACE(HINSTANCE hInstance);
	static void SetCurrentSpriteHandler(LPD3DXSPRITE mSpriteHandler);
	static void SetCurrentDevice(LPDIRECT3DDEVICE9 mDevice);

	static void SetWidth(int width);
	static int  GetWidth();

	static void SetHeight(int height);
	static int  GetHeight();

	static void  SetFPS(float fps);
	static float GetFPS();
};
