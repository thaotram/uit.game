#include "Scene_Kiss.h"
#include "Scene_Start.h"

#include "../../Define.h"
#include "../Object_Screen/Object_Screen.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#define xx mPos.x()
#define yy mPos.y()

Scene_Kiss::Scene_Kiss() : Scene() {
	oObjectStore = new Scene_ObjectStore("");
	oPlayer = new Object_Unit_Aladdin(250, 200);
	oPlayer->GetAnimation()->Set("kiss", 1);
	((Object_Screen *)oTransparentScreen)->mAlpha = 0;
	mTime = 0;
	isNext = false;
}

void Scene_Kiss::SceneRender(float delay) {
	mTime += delay;
	if (mTime > 3.f && !isNext)
	{
		isNext = true;
		NextScene(new Scene_Start());
	}
	//# Update
	oPlayer->ObjectUpdateEvent(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);

	mCamera = V2{ 0,0 };

	//# Render
	oPlayer->ObjectRender(delay);
	oTransparentScreen->ObjectRender(delay);
}
