#pragma once
#include <list>

#include "GameGlobal.h"
#include "Unit.h"

using namespace std;

class Scene
{
private:
	void EachUnit(function<void(Unit *)> eachUnit) {
		for (auto &container : mContainers) {
			for (auto &unit : container.second) {
				eachUnit(unit.second);
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
		AfterUpdateUnit();
	};
	void Draw() {
		EachUnit([=](Unit * item) {
			item->Draw();
		});
		AfterDrawUnit();
	};
	virtual void AfterDrawUnit() {}
	virtual void AfterUpdateUnit() {}

	void AddChild(string pPart, string pUnitName, Unit * pUnit) {
		mContainers[pPart][pUnitName] = pUnit;
	}
	void RemoveChild(string pPart, string pUnitName) {
		mContainers[pPart].erase(pUnitName);
	}
	Unit * GetUnit(string pPart, string pUnitName) {
		mContainers[pPart][pUnitName];
	}
	virtual void OnKeyDown(int pKeyCode) {};
	virtual void OnKeyUp(int pKeyCode) {};
	virtual void OnMouseDown(float x, float y) {};

	map<string, Unit *> operator[](string pPart) {
		return mContainers[pPart];
	}
};