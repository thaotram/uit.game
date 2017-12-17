#pragma once
#include "Game.h"

Game::Game() {
	mDevice = GameGlobal::GetDevice();

	//# Game Start
	Scene::ReplaceScene(
		new Scene_AgrabahMarket()
	);
	mScene = Scene::mScene;

	InitLoop();
}
Game::~Game() {}

void Game::InitLoop() {
	MSG msg;
	float
		timePerFrame = 1.f / FPS,		// Tickperframe là khoảng thời gian hiển thị của mỗi frame
		delay = 0;						// Delta chứa tổng tgian thực hiện của mỗi vòng while
	
	while (GameGlobal::isGameRunning) {
		GameTime::StartCounter();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		delay += GameTime::GetCounter();
		if (delay >= timePerFrame) {
			if (delay < timePerFrame * 3) {
				GameRender(delay);
			}
			delay -= timePerFrame;
		}
		else {
			Sleep(
				(DWORD)((timePerFrame - delay)) // milisecond
				// Do bị dôi ra một khoảng thời gian sau khi thực hiện hàm GameRender
				// ở phía trên nên đoạn này nó cần sleep ít hơn thực tế 1 chút
				// Nếu để sleep lỗi như này thì trong 1 vòng nó sẽ sleep nhiều khoảng rất nhỏ 
				// (khoảng 1000 lần)
				// (DWORD)((timePerFrame - delay) * 1000) // milisecond
			);
			delay = timePerFrame;
		}
	}
}

//# Được gọi bên trong vòng lặp
void Game::GameRender(float delay) {
	ID3DXSprite  * mSpriteHandler = GameGlobal::GetSpriteHandler();

	// Before
	mDevice->Clear(0, NULL, D3DCLEAR_TARGET, BACKGROUND_COLOR, 0.f, 0);
	mDevice->BeginScene();
	mSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	// ?
	mDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
	mDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	mDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
	// Render
	mScene->SceneRender(delay);

	// End
	mSpriteHandler->End();
	mDevice->EndScene();
	mDevice->Present(0, 0, 0, 0);
}