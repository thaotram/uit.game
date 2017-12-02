#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <windows.h>
#include <map>
#include <bitset>

using namespace std;

class GameGlobal
{
private:
	static HWND					mHwnd;				// hwnd hiện tại
	static HINSTANCE			mHInstance;			// hInstance của windows hiện tại
	static LPD3DXSPRITE			mSpriteHandler;		// spriteHanlder hiện tại
	static LPDIRECT3DDEVICE9	mDevice;			// device directX hiện tại
	static map<int, bool>		mInput;
public:
	GameGlobal();
	~GameGlobal();

	static bool isGameRunning; //trạng thái xem game có đang chạy khong

	static HWND GetHWND();
	static HINSTANCE GetHINSTACE();
	static LPD3DXSPRITE GetSpriteHandler();
	static LPDIRECT3DDEVICE9 GetDevice();

	static void SetHWND(HWND hwnd);
	static void SetHINSTACE(HINSTANCE hInstance);
	static void SetSpriteHandler(LPD3DXSPRITE spriteHandler);
	static void SetDevice(LPDIRECT3DDEVICE9 device);

	static bitset<8> Input;
	static map<int, bool> * GetInput() {
		return &mInput;
	};
};
