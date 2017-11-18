#include "Scene_AgrabahMarket.h"
#include "Unit_Aladdin.h"

AgrabahMarket::AgrabahMarket() {
	(*this)("2_Char", new Unit_Aladdin());
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
