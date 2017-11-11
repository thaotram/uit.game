#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

class Game
{
public:
	Game();
	~Game();

protected:
	float               mFPS;
	D3DCOLOR            mBackgroundColor;
	LPDIRECT3DDEVICE9	mDevice;

	//khởi tạo vòng lặp game
	//đc gọi khi khởi tạo đối tượng game
	void InitLoop();

	//hàm dùng để vẽ sau khi update
	void Render();

	//hàm update của game
	void Update(float dt);
};
