#include "Aladdin.h"

Aladdin::Aladdin() :
	Unit("Aladdin", 0xffff00ff)
{
	this->SetScale(4, 4);
	this->SetPosition(200, 200);
}

Aladdin::~Aladdin() {}
