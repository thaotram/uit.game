#include "Scene_Start.h"

#include "../../Define.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Static_Knife.h"

#define I GameGlobal::Input
#define Z I[CHAR_Z]
#define X I[CHAR_X]
#define C I[CHAR_C]
#define alpha oTransparentScreen->mAlpha
#define KnifeX oKnife->GetPosition()->x

Scene_Start::Scene_Start() : Scene(){
	delete mBackScene;
	oMapBackground = new Object_Screen("Option_Scene", "main_menu");
	oKnife = new Object_Unit_Static_Knife(70,126);
	oKnife->GetPosition()->x.mType = linear;
	oKnife->GetPosition()->x.mVelocity = 50;
	alpha = 0;
	isNext = false;

	Scene::mBlood = 7;
	Scene::mApple = 10;
	Scene::mSpendthese = 0;
	Scene::mExtrahealth = 3;
	Scene::mScore << 0;
}

void Scene_Start::SceneRender(float delay)
{
	if ((Z || X || C) && !isNext) {
		isNext = true;
		Z = X = C = false;
		Scene::NextScene(new Scene_Items());
	}
	KnifeX.Update(delay);
	if (KnifeX() >= 70) {
		KnifeX = 60;
	}
	else if (KnifeX() <= 60) {
		KnifeX = 70;
	}

	oMapBackground->ObjectUpdateEvent(delay);
	oKnife->ObjectUpdateEvent(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);

	oMapBackground->ObjectRender(delay);
	oKnife->ObjectRender(delay);
	oTransparentScreen->ObjectRender(delay);
}