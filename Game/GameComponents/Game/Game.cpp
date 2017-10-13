#include "Game.h"
#include "GameGlobal.h"
#include "../../GameComponents/Game/GameTime.h"
#include "../../GameControllers/SceneManager.h"
#include "../../Scenes/DemoScene.h"

Game::Game()
{
	mFPS = GameGlobal::GetFPS();

	SceneManager::GetInstance()->ReplaceScene(
		new DemoScene()
	);

	InitLoop();
}
Game::~Game() {}

void Game::InitLoop()
{
	MSG msg;
	float
		tickPerFrame = 1.0f / mFPS,		// Tickperframe là khoảng thời gian hiển thị của mỗi frame
		delta = 0;						// Delta chứa tổng tgian thực hiện của mỗi vòng while

	while (GameGlobal::isGameRunning)
	{

		GameTime::GetInstance()->StartCounter();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		delta += GameTime::GetInstance()->GetCouter();

		// vòng while đã chạy tgian lâu hơn hoặc bằng fps mình yêu cầu thì thực hiện update game và render lên màn hình
		if (delta >= tickPerFrame)
		{
			Update(delta);
			//delta -= tickPerFrame;
			delta = 0;
		}
		else // fps cao hơn lúc bth, tạm sleep lại bằng khoảng tgian nó nhanh hơn, sau đó sẽ update và render tiếp
		{
			Sleep((DWORD)((tickPerFrame - delta) * 1000));
			delta = tickPerFrame;
		}
	}
}

// Được gọi bên trong vòng lặp (bên trong hàm update)
void Game::Render() {
	auto device = GameGlobal::GetCurrentDevice();
	Scene * scene = SceneManager::GetInstance()->GetCurrentScene();

	device->Clear(0, NULL, D3DCLEAR_TARGET, scene->GetBackcolor(), 0.0f, 0);
	{
		device->BeginScene();
		GameGlobal::GetCurrentSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);
		device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
		device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
		device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
		scene->Draw();
		GameGlobal::GetCurrentSpriteHandler()->End();
		device->EndScene();
	}
	device->Present(0, 0, 0, 0);
}

// Được gọi bên trong vòng lặp
void Game::Update(float delta) {
	SceneManager::GetInstance()->GetCurrentScene()->Update(delta);
	Render();
}