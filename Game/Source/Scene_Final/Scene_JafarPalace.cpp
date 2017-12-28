#include "Scene_JafarPalace.h"

#include "../../Define.h"
#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Map_Final/Object_Map_JafarPalace_Background.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Enemy_Jafar.h"

Scene_JafarPalace::Scene_JafarPalace() : Scene() {
    oObjectStore = new Scene_ObjectStore("JafarPalace_Block");
    oStatus = new Scene_Status();

	mStartPoint = { 90, 352 };
	oPlayer = new Object_Unit_Aladdin(mStartPoint.x, mStartPoint.y);

    oBoss = new Object_Unit_Enemy_Jafar(412, 326);
    oMapBackground = new Object_Screen("Screen", "JafarPalace_Background");
    oMapBack = new Object_Map_JafarPalace_Back();
    oMapBack->AfterAddToScene();

	Scene::mRestartPoint = NULL;
	((Object_Screen *)oTransparentScreen)->mAlpha = 0;

    mSound = new GameSound(L"Sound/OST/16_Boss Tune.wav");
}

void Scene_JafarPalace::SceneRender(float delay) {
	if (mApple == 0 && oObjectStore->mStatic_Apple.size() == 0) {
		delete oObjectStore;
		oObjectStore = new Scene_ObjectStore("JafarPalace_Block");
	}
    //# Update
    Scene::mScore.Update(delay);
    
    oPlayer->ObjectUpdateEvent(delay);
    oObjectStore->ObjectUpdateEvent(delay);
	oBoss->ObjectUpdateEvent(delay);
    oMapBack->ObjectUpdateEvent(delay);
    oMapBackground->ObjectUpdateEvent(delay);
    oStatus->ObjectUpdateEvent(delay);
    oTransparentScreen->ObjectUpdateEvent(delay);

    //# Remove item in RemoveList
    oObjectStore->ObjectRemoveMarkedDelete();

    //# Render
    oMapBackground->ObjectRender(delay);
    oMapBack->ObjectRender(delay);
	oBoss->ObjectRender(delay);
    oObjectStore->ObjectRender(delay);
    oPlayer->ObjectRender(delay);
    oStatus->ObjectRender(delay);
    oTransparentScreen->ObjectRender(delay);
}
