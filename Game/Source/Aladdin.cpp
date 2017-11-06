#include "Aladdin.h"

Aladdin::Aladdin() :
	Unit("Aladdin", 0xffff00ff)
{
	this->SetScale(3, 3);
	this->SetPosition(200, 200);
}

Aladdin::~Aladdin() {}
