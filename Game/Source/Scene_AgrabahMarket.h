#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Scene.h"
#include "GameDebug.h"

#include "Unit_Aladdin.h";
#include "Unit_Camel.h";
#include "Unit_Peddler.h";
#include "Unit_Genie.h";
#include "Unit_Guards.h";
#include "Unit_Status.h";
#include "Unit_Item.h";

using namespace std;

Unit * sMap;
Unit * sChar;

class AgrabahMarket : public Scene
{
public:
	AgrabahMarket() {
		sMap = new Unit("AgrabahMarket");
		this->AddChild("1_Map", "1", sMap);
		sMap->SetPosition(0, 480);

		/*sChar = new Unit_Aladdin();
		this->AddChild("2_char", "char", sChar);
		sChar->SetPosition(GameGlobal::GetWidth() / 2, 189 * GameGlobal::GetScale());
		sChar->GetAnimation()->SetState("die");*/

		////(*this)["2"]["1"]->log = true;

		sChar = new Unit_Peddler();
		this->AddChild("2_char", "char", sChar);
		sChar->SetPosition(GameGlobal::GetWidth() / 2, 189 * GameGlobal::GetScale());
		sChar->GetAnimation()->SetState("peddler_show");

	}
	void AfterDrawUnit() {
		GameDebug::DrawHL(480, 1);
		//GameDebug::DrawVL(300, 1);
		//GameDebug::DrawVL(600, 1);
	}
	void AfterUpdateUnit() {
		//sMap->SetPositionTo(-1, 0);
	}
	void OnKeyDown(int pKeyCode) {
		switch (pKeyCode)
		{
		case VK_LEFT:
			sChar
				->GetAnimation()->SetState("stand_still");
			break;
		case VK_RIGHT:
			sChar
				->GetAnimation()->SetState("run");
			break;
		default:
			break;
		}
		if (pKeyCode == VK_LEFT) {
		}
	}
};

