#pragma once
#include <list>

#include "GameGlobal.h"
#include "Unit.h"

using namespace std;

class Scene
{
private:
	void EachUnit(function<void(list<Unit *>::iterator)> eachFunction) {
		for (auto &it : mContainers) {
			for (list<Unit *>::iterator unit = it.second.begin(); unit != it.second.end(); ++unit) {
				eachFunction(unit);
			}
		}
	}
protected:
	map<string, list<Unit *>> mContainers;
public:
	Scene() {};
	~Scene() {
		EachUnit([=](list<Unit *>::iterator item) {
			delete *item;
		});
	};
	void Update(float dt) {
		EachUnit([=](list<Unit *>::iterator item) {
			(**item).Update(dt);
		});
	};
	void Draw() {
		EachUnit([=](list<Unit *>::iterator item) {
			(**item).Draw();
		});
	};

	void AddChild(string pPart, Unit * pUnit) {
		mContainers[pPart].push_back(pUnit);
	}
	void RemoveChild(string pPart, Unit * pUnit) {
		mContainers[pPart].remove(pUnit);
	}

	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
	virtual void OnMouseDown(float x, float y) {};
};