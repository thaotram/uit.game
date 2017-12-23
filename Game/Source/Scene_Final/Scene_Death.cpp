#include "Scene_Death.h"

#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

Scene_Death::Scene_Death() : Scene() {
    oObjectStore = new Scene_ObjectStore("");
    oPlayer = new Object_Unit_Aladdin(160, 150);
    oPlayer->GetAnimation()->Set("die", 1);
    oAbu = new Object_Unit_NPC_Abu(160 + 90, 150 + 19);

    mTimer = 0;
}

Scene_Death::~Scene_Death() {
    delete oAbu;
    delete oPlayer;
}

void Scene_Death::SceneRender(float delay) {
	if (mNextScene == NULL) {
		// mTimer += delay;
		// if(mTimer > 3.f) {
		// 	Scene::NextScene(Scene::mBackScene);
		// 	mExtrahealth = max(0, mExtrahealth - 1);
		// 	mBlood = 7;
		// }
	}
 
    oPlayer->ObjectUpdateEvent(delay);
    oAbu->ObjectUpdateEvent(delay);
    Scene::oTransparentScreen->ObjectUpdateEvent(delay);

    oPlayer->ObjectRender(delay);
    oAbu->ObjectRender(delay);
    Scene::oTransparentScreen->ObjectRender(delay);
}