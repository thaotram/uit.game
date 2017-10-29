#include <d3d9.h>
#include <d3dx9.h>

#include <sstream>
#include <iostream>
#include <dinput.h>
#include <windows.h>
#include <windowsx.h>

#include "GameComponents\Game\Game.h"
#include "GameComponents\Game\GameGlobal.h"
#include "GameControllers\SceneManager\SceneManager.h"

#include <iostream>
#include <json.hpp>
#include <fstream>

using json = nlohmann::json;
using namespace std;

//#include "GameComponents\GameTime.h"

#define APP_CLASS L"Game"
#define MAIN_WINDOW_TITLE L"Game Title"
#define APP_WIDTH 600
#define APP_HEIGHT 600
#define FPS 60
#define KEYBOARD_BUFFERD_SIZE 1024

int InitializeWindow(int cmdShow);
int InitializeDevice();
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//! Entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow)
{
	GameGlobal::SetCurrentHINSTACE(hInstance);
	InitializeWindow(cmdShow);
	return 0;
}

// Được gọi trong hàm main
int InitializeWindow(int cmdShow)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	//wc.style = 0;
	wc.hInstance = GameGlobal::GetCurrentHINSTACE();

	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APP_CLASS;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	RECT wr = { 0, 0, APP_WIDTH, APP_HEIGHT };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	GameGlobal::SetFPS(FPS);
	GameGlobal::SetHeight(wr.bottom - wr.top);
	GameGlobal::SetWidth(wr.right - wr.left);

	GameGlobal::SetCurrentHWND(
		CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			APP_CLASS,
			APP_CLASS,
			WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			GameGlobal::GetWidth(),
			GameGlobal::GetHeight(),
			NULL,
			NULL,
			GameGlobal::GetCurrentHINSTACE(),
			NULL
		)
	);

	ShowWindow(
		GameGlobal::GetCurrentHWND(),
		cmdShow
	);
	UpdateWindow(
		GameGlobal::GetCurrentHWND()
	);

	if (InitializeDevice())
	{
		new Game();
	}

	return 0;
}

// Được gọi trong hàm InitializeWindow trong hàm main
int InitializeDevice()
{
	D3DPRESENT_PARAMETERS d3dpp;
	LPD3DXSPRITE mSpriteHandler;

	LPDIRECT3DDEVICE9 mDevice;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = GameGlobal::GetWidth();
	d3dpp.BackBufferHeight = GameGlobal::GetHeight();

	// IDirect3DDevice9Ex_SetRenderState

	Direct3DCreate9(D3D_SDK_VERSION)->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		GameGlobal::GetCurrentHWND(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&mDevice
	);
	GameGlobal::SetCurrentDevice(mDevice);

	D3DXCreateSprite(
		mDevice,
		&mSpriteHandler
	);
	GameGlobal::SetCurrentSpriteHandler(mSpriteHandler);

	return 1;
}

// Được gọi trong hàm InitializeWindow trong hàm main
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// Message ở đây là các event của windows
	switch (message)
	{
	case WM_DESTROY:
		GameGlobal::isGameRunning = false;
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		SceneManager::GetInstance()->GetCurrentScene()
			->OnMouseDown((float)GET_X_LPARAM(lParam), (float)GET_Y_LPARAM(lParam));
		break;
	case WM_KEYDOWN:
		SceneManager::GetInstance()->GetCurrentScene()->OnKeyDown(wParam);
		break;
	case WM_KEYUP:
		SceneManager::GetInstance()->GetCurrentScene()->OnKeyUp(wParam);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}