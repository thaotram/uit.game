#pragma once
#include <list>

#include "GameGlobal.h"
#include "Unit.h"

using namespace std;

class Scene
{
private:
	void EachUnit(function<void(Unit *)> eachUnit);
protected:
	map<string, Unit *> mUnits;
public:
	Scene();
	~Scene();
	void Update(float dt);
	void Draw();

	void AddChild(string pUnitName, Unit * pUnit);
	void RemoveChild(string pUnitName);
	virtual void OnKeyDown(int pKeyCode);
	virtual void OnKeyUp(int pKeyCode);
	virtual void OnMouseDown(float x, float y);

	Unit * GetUnit(string pUnitName);
	Unit * operator[](string pUnitName);
	Unit * operator()(string pUnitName);
	void operator()(string pUnitName, Unit * pUnit);
};