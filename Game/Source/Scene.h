#pragma once
#include <list>

#include "GameGlobal.h"
#include "Unit.h"

using namespace std;

class Scene
{
private:
	void EachUnit(function<void(Unit *)> eachFunction) {
		for (auto &container : mContainers) {
			for (auto &unit : container.second) {
				eachFunction(unit.second);
			}
		}
	}
protected:
	map<string, map<string, Unit *>> mContainers;
public:
	Scene() {};
	~Scene() {
		EachUnit([=](Unit * item) {
			delete item;
		});
	};
	void Update(float dt) {
		EachUnit([=](Unit * item) {
			item->Update(dt);
		});
	};
	void Draw() {
		EachUnit([=](Unit * item) {
			item->Draw();
		});
	};

	void AddChild(string pPart, string pUnitName, Unit * pUnit) {
		mContainers[pPart][pUnitName] = pUnit;
	}
	void RemoveChild(string pPart, string pUnitName) {
		mContainers[pPart].erase(pUnitName);
	}

	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
	virtual void OnMouseDown(float x, float y) {};
};