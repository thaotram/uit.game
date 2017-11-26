#pragma once
#include <list>
#include <functional> 
#include "GameGlobal.h"
#include "Unit_Vector2.h"

using namespace std;
class Unit;

class Scene : public map<string, Unit *>
{
private:
	void EachUnit(function<void(Unit *)> pEachUnit);
public:
	Scene();
	~Scene();

	Unit_Vector2 mCameraPosition;		// Tính từ góc trên bên phải của camera

	void Update(float dt);
	void Draw();

	void OnKeyDown(int pKeyCode);
	void OnKeyUp(int pKeyCode);
	void OnMouseDown(float pX, float pY) {};

	void Add(string pName, Unit * pUnit);
};