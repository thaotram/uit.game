#pragma once
#include "Game.h"
#include "GameGlobal.h"
#include "GameTime.h"
#include "SceneManager.h"
#include "Scene_AgrabahMarket.h"

Game::Game()
{
	mFPS = GameGlobal::GetFPS();
	mBackgroundColor = GameGlobal::GetBackgroundColor();
	mDevice = GameGlobal::GetDevice();

	// Game Start
	SceneManager::GetInstance()->ReplaceScene(
		new AgrabahMarket()
	);

	InitLoop();
}
Game::~Game() {}

void Game::InitLoop()
{
	MSG msg;
	float
		timePerFrame = 1.0f / mFPS,		// Tickperframe là khoảng thời gian hiển thị của mỗi frame
		delta = 0;						// Delta chứa tổng tgian thực hiện của mỗi vòng while

	while (GameGlobal::isGameRunning)
	{

		GameTime::GetInstance()->StartCounter();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		delta += GameTime::GetInstance()->GetCounter();

		// vòng while đã chạy tgian lâu hơn hoặc bằng fps mình yêu cầu thì thực hiện update game và render lên màn hình
		if (delta >= timePerFrame)
		{
			Update(delta);
			delta -= timePerFrame;
		}
		else // fps cao hơn lúc bth, tạm sleep lại bằng khoảng tgian nó nhanh hơn, sau đó sẽ update và render tiếp
		{
			Sleep((DWORD)((timePerFrame - delta) * 1000));
			delta = timePerFrame;
		}
	}
}

// Được gọi bên trong vòng lặp (bên trong hàm update)
void Game::Render() {
	Scene * scene = SceneManager::GetInstance()->GetCurrentScene();
	mDevice->Clear(0, NULL, D3DCLEAR_TARGET, mBackgroundColor, 0.0f, 0);
	{
		mDevice->BeginScene();
		GameGlobal::GetSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);
		{
			// Làm cho hình ảnh sau khi scale không bị nhòe
			mDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
			mDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
			mDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
		}
		scene->Draw();
		GameGlobal::GetSpriteHandler()->End();
		mDevice->EndScene();
	}
	mDevice->Present(0, 0, 0, 0);
}

// Được gọi bên trong vòng lặp
void Game::Update(float delta) {
	SceneManager::GetInstance()->GetCurrentScene()->Update(delta);
	Render();
}