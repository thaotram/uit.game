#pragma once
#include <list>
#include <functional>
#include "../GameGlobal.h"
#include "../Scene/Scene_Camera.h"

using namespace std;
class Object;

class Scene : public map<string, Object *> {
private:
	static Scene * mCurrentScene;
	void EachObject(function<void(Object *)> pEachUnit);
public:
	Scene();
	~Scene();

	Scene_Camera mCamera;		// Tính từ góc trên bên phải của camera

	void SceneRender(float delay);

	void OnKeyDown(int pKeyCode);
	void OnKeyUp(int pKeyCode);
	void OnMouseDown(float pX, float pY) {};

	void Add(string pName, Object * pObject);

	static void ReplaceScene(Scene * pScene);
	static Scene * GetCurrentScene();
};