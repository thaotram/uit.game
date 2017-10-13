#include "DemoScene.h"

#include "../GameComponents/Unit/Unit.h"
#include "../GameComponents/Sprite/Sprite.h"

Unit * mUnits;
Unit * mAladdin;

DemoScene::DemoScene()
{
	LoadContent();
}

void DemoScene::LoadContent()
{
	//set màu backcolor cho scene ở đây là màu xanh
	mBackColor = 0xdddddd;

	mUnits = new Unit("Block");
	mUnits->GetSprite()->SetPosition(150, 150);
	mUnits->GetSprite()->SetScale(5, 5);
	//mUnits->GetSprite()->SetScale(0.8f, 0.8f);

	//mAladdin = new Unit("Aladdin");
	//mAladdin->GetSprite()->SetScale(5, 5);
	//mAladdin->GetSprite()->SetPosition(220, 220);
}

void DemoScene::Update(float dt)
{
	mUnits->Update(dt);
	//mAladdin->Update(dt);
}

void DemoScene::Draw()
{
	mUnits->Draw();
	//mAladdin->Draw();
}