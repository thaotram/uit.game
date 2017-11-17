#include "Scene_AgrabahMarket.h"

Unit * sChar;
float x;

AgrabahMarket::AgrabahMarket() {
	sChar = new Unit("Aladdin");
	this->AddChild("1_Map", "1", sChar);
	sChar->SetPosition(0, 480);
}

void AgrabahMarket::AfterDrawUnit() {
	//sChar->Draw();
}

void AgrabahMarket::AfterUpdateUnit() {
	x = x + 1;
	sChar->SetPosition(x, 480);
}

void AgrabahMarket::OnKeyDown(int pKeyCode) {
	switch (pKeyCode)
	{
	case VK_LEFT:
		break;
	case VK_RIGHT:
		break;
	default:
		break;
	}
}
