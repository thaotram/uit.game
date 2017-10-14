#include "DemoScene.h"

#include "../GameComponents/Unit/Unit.h"
#include "../GameComponents/Sprite/Sprite.h"

//Unit * mUnits;
Unit * mAladdin;

DemoScene::DemoScene()
{
	LoadContent();
}

void DemoScene::LoadContent()
{
	mBackColor = 0xdddddd;

	mAladdin = new Unit("Aladdin", 0xffff00ff);
	mAladdin->GetSprite()->SetScale(3, 3);
	mAladdin->GetSprite()->SetPosition(220, 220);
}

void DemoScene::Update(float dt)
{
	mAladdin->Update(dt);
}

void DemoScene::Draw()
{
	mAladdin->Draw();
}

void DemoScene::OnKeyDown(int keyCode)
{
	if (keyCode == VK_LEFT)
	{
		mAladdin->GetSprite()->SetPositionTo(-10, 0);
	}

	if (keyCode == VK_RIGHT)
	{
		mAladdin->GetSprite()->SetPositionTo(10, 0);
	}

	if (keyCode == VK_UP) {
		mAladdin->SetFrame(1);
	}
	if (keyCode == VK_DOWN) {}
}

void DemoScene::OnKeyUp(int keyCode)
{
}

void DemoScene::OnMouseDown(float x, float y)
{
}
