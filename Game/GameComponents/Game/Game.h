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
	PDIRECT3DSURFACE9	mBackground, mBackBuffer;
	int					mWidth, mHeight;
	static int          mIsDone;
	float               mFPS;

	//khởi tạo vòng lặp game
	//đc gọi khi khởi tạo đối tượng game
	void InitLoop();

	//hàm dùng để vẽ sau khi update
	void Render();

	//hàm update của game
	void Update(float dt);
};
