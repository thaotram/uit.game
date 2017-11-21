#pragma once
#include <list>

#include "GameGlobal.h"
#include "Unit.h"

using namespace std;

class Scene : public map<string, Unit *>
{
private:
	void EachUnit(function<void(Unit *)> pEachUnit);
public:
	Scene();
	~Scene();
	void Update(float dt);
	void Draw();

	void OnKeyDown(int pKeyCode);
	void OnKeyUp(int pKeyCode);
	void OnMouseDown(float pX, float pY) {}
};