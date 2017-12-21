#include "Scene_JafarPalace.h"

#include "../Object_Map_Final/Object_Map_JafarPalace_Back.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../../Define.h"

Scene_JafarPalace::Scene_JafarPalace() : Scene() {
	oObjectStore = new Scene_ObjectStore("JafarPalace_Block");
	oPlayer = new Object_Unit_Aladdin(200, 50);
	oMapBack = new Object_Map_JafarPalace_Back();
	
	oMapBack->AfterAddToScene();
}