#pragma once
#include <list>
#include <functional> 
#include "../GameGlobal.h"
#include "../Object/Object_Vector2.h"

using namespace std;
class Object;

class Scene : public map<string, Object *>
{
private:
	void EachObject(function<void(Object *)> pEachUnit);
public:
	Scene();
	~Scene();

	Object_Vector2 mCameraPosition;		// Tính từ góc trên bên phải của camera

	void SceneRender(float delay);

	void OnKeyDown(int pKeyCode);
	void OnKeyUp(int pKeyCode);
	void OnMouseDown(float pX, float pY) {};

	void Add(string pName, Object * pObject);
};