#include <d3d9.h>
#include <d3dx9.h>

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <windowsx.h>

#include <json.hpp>

#include "Source/Game.h"
#include "Source/GameGlobal.h"
#include "Source/SceneManager.h"

using json = nlohmann::json;
using namespace std;

//#include "GameComponents\GameTime.h"

#define APP_CLASS L"Game"
#define MAIN_WINDOW_TITLE L"Game Title"
#define APP_WIDTH 320
#define APP_HEIGHT 224
#define APP_SCALE 3
#define FPS 120
#define BACKGROUND_COLOR 0xffffffff

void InitializeWindow(int cmdShow);
int InitializeDevice();
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//! Entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow)
{
	GameGlobal::SetHINSTACE(hInstance);
	InitializeWindow(cmdShow);
	return 0;
}

// Được gọi trong hàm main
void InitializeWindow(int cmdShow)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = GameGlobal::GetHINSTACE();

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

	GameGlobal::SetScale(APP_SCALE);
	GameGlobal::SetWidth(APP_WIDTH * APP_SCALE);
	GameGlobal::SetHeight(APP_HEIGHT * APP_SCALE);
	GameGlobal::SetBackgroundColor(BACKGROUND_COLOR);
	GameGlobal::SetFPS(FPS);
	GameGlobal::SetHWND(
		CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			APP_CLASS,
			APP_CLASS,
			WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX ^ WS_CAPTION,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			GameGlobal::GetWidth(),
			GameGlobal::GetHeight(),
			NULL,
			NULL,
			GameGlobal::GetHINSTACE(),
			NULL
		)
	);

	ShowWindow(
		GameGlobal::GetHWND(),
		cmdShow
	);
	UpdateWindow(
		GameGlobal::GetHWND()
	);

	if (InitializeDevice())
	{
		new Game();
	}
}

// Được gọi trong hàm InitializeWindow trong hàm main
int InitializeDevice()
{
	D3DPRESENT_PARAMETERS d3dpp;
	LPD3DXSPRITE pSpriteHandler;
	D3DXMATRIX pTransform;
	LPDIRECT3DDEVICE9 pDevice;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = GameGlobal::GetWidth();
	d3dpp.BackBufferHeight = GameGlobal::GetHeight();

	Direct3DCreate9(D3D_SDK_VERSION)->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		GameGlobal::GetHWND(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&pDevice
	);
	GameGlobal::SetDevice(pDevice);

	D3DXCreateSprite(
		pDevice,
		&pSpriteHandler
	);
	D3DXMatrixTransformation2D(
		&pTransform,
		NULL, NULL, NULL, NULL, 0, NULL
	);
	pSpriteHandler->SetTransform(&pTransform);
	GameGlobal::SetSpriteHandler(pSpriteHandler);

	return 1;
}

// Được gọi trong hàm InitializeWindow trong hàm main
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	map<int, bool> * GameInput = GameGlobal::GetInput();
	// Message ở đây là các event của windows
	switch (message)
	{
	case WM_DESTROY:
		GameGlobal::isGameRunning = false;
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		SceneManager::GetInstance()->GetCurrentScene()->OnMouseDown(
			(float)GET_X_LPARAM(lParam),
			(float)GET_Y_LPARAM(lParam)
		);
		break;
	case WM_KEYDOWN:
		//SceneManager::GetInstance()->GetCurrentScene()->OnKeyDown(wParam);
		(*GameInput)[wParam] = true;
		break;
	case WM_KEYUP:
		//SceneManager::GetInstance()->GetCurrentScene()->OnKeyUp(wParam);
		(*GameInput)[wParam] = false;
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}