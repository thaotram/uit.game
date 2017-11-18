#pragma once
#include <list>

#include "GameGlobal.h"
#include "Unit.h"

using namespace std;

class Scene: public map<string, Unit *>
{
private:
	void EachUnit(function<void(Unit *)> pEachUnit);
public:
	Scene();
	~Scene();
	void Update(float dt);
	void Draw();

	virtual void OnKeyDown(int pKeyCode);
	virtual void OnKeyUp(int pKeyCode);
	virtual void OnMouseDown(float pX, float pY);
};