#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <windows.h>
#include <map>

using namespace std;

class GameGlobal
{
private:
	static HWND					mHwnd;				// hwnd hiện tại
	static HINSTANCE			mHInstance;			// hInstance của windows hiện tại
	static LPD3DXSPRITE			mSpriteHandler;		// spriteHanlder hiện tại
	static LPDIRECT3DDEVICE9	mDevice;			// device directX hiện tại
	static D3DCOLOR				mBackgroundColor;	// backgroundColor
	static int					mWidth, mHeight;	// size của cửa sổ
	static float				mFPS;				// frame per second
	static float				mScale;				// Scale
	static map<int, bool>		mInput;
public:
	GameGlobal();
	~GameGlobal();

	static bool isGameRunning; //trạng thái xem game có đang chạy khong

	static HWND GetHWND();
	static HINSTANCE GetHINSTACE();
	static LPD3DXSPRITE GetSpriteHandler();
	static LPDIRECT3DDEVICE9 GetDevice();
	static D3DCOLOR GetBackgroundColor();

	static void SetHWND(HWND hwnd);
	static void SetHINSTACE(HINSTANCE hInstance);
	static void SetSpriteHandler(LPD3DXSPRITE spriteHandler);
	static void SetDevice(LPDIRECT3DDEVICE9 device);
	static void SetBackgroundColor(D3DCOLOR backgroundColor);

	static void SetWidth(int width);
	static int  GetWidth();

	static void SetHeight(int height);
	static int  GetHeight();

	static void  SetFPS(float fps);
	static float GetFPS();

	static void  SetScale(float scale);
	static float GetScale();

	static map<int, bool> * GetInput() {
		return &mInput;
	};
};
