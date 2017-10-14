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
	//set màu backcolor cho scene ở đây là màu xanh
	mBackColor = 0xdddddd;

	//mUnits = new Unit("Block");
	//mUnits->GetSprite()->SetPosition(50, 50);
	//mUnits->GetSprite()->SetScale(4, 4);

	mAladdin = new Unit("Aladdin", 0xffff00ff);
	mAladdin->GetSprite()->SetScale(3, 3);
	mAladdin->GetSprite()->SetPosition(220, 220);
}

void DemoScene::Update(float dt)
{
	//mUnits->Update(dt);
	mAladdin->Update(dt);
}

void DemoScene::Draw()
{
	//mUnits->Draw();
	mAladdin->Draw();
}