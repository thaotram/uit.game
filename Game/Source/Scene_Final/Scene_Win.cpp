#include "Scene_Win.h"

#include "../../Define.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#include "../Scene_Final/Scene_Kiss.h"
#define xx mPos.x()
#define yy mPos.y()

Scene_Win::Scene_Win() : Scene() {
	oObjectStore = new Scene_ObjectStore("");
	oPlayer = new Object_Unit_Aladdin(0, 150);
	oPlayer->GetPosition()->x.mType = linear;
	oPlayer->GetPosition()->y.mType = linear;
	oPlayer->GetPosition()->x.mVelocity = 100.f;
	oPlayer->GetPosition()->y.mVelocity = 20.f;
	oPlayer->GetPosition()->operator=(V2{400, 70});
	oPlayer->GetAnimation()->Set("flying_carpet", 1);
	
	oMapBackground = new Object_Screen("Aladdin_Miscellaneous_Cutscenes", "End");
	// oMapBackground = new Object_Screen("Aladdin_Miscellaneous_Cutscenes", "End");

	((Object_Screen *)oTransparentScreen)->mAlpha = 0;
	isNext = false;
}

void Scene_Win::SceneRender(float delay) {
	if (oPlayer->GetPosition()->x() > 320 && !isNext) {
		isNext = true;
		NextScene(new Scene_Kiss());
	}
	
	//# Update
	oMapBackground->ObjectUpdateEvent(delay);
	oPlayer->ObjectUpdateEvent(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);

	mCamera = V2{ 0,0 };

	//# Render
	oMapBackground->ObjectRender(delay);
	oPlayer->ObjectRender(delay);
	oTransparentScreen->ObjectRender(delay);
}
