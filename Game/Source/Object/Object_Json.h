#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>

#include <json.hpp>
#include "Object_Animation.h"

using namespace std;
using json = nlohmann::json;
struct Frame;
typedef Frame FRAME;
struct State;
typedef State STATE;
class Object_Json;

struct Frame {
	Frame() {}
	Frame(
		RECT inRect, D3DXVECTOR2 inTranslation
	) : Rect(inRect), Transition(inTranslation) {}
	RECT Rect;
	D3DXVECTOR2 Transition;
};

struct State {
	State() {};
	State(
		D3DXVECTOR2 pBasePoint, vector<int> pFrameCycle, map<int, FRAME> pFrame
	) : BasePoint(pBasePoint), FrameCycle(pFrameCycle), FrameList(pFrame) {};

	D3DXVECTOR2			BasePoint;
	vector<int>			FrameCycle;
	map<int, FRAME>		FrameList;
};

//class Object_Animation;
class Object;

class Object_Json : public map<string, STATE> {
private:
	static map<string, Object_Json *> Object_Jsons;

	STATE operator[](string pState);
	Object_Json(string pName);
public:
	static Object_Json * GetJson(string pName);

	RECT GetFrame(string mState, int mFrameIndex);
	D3DXVECTOR2 GetTransition(string pState, int pFrameIndex);
	D3DXVECTOR2 GetBasePoint(string pState, int pFrameIndex);
	vector<int> GetFrameCycle(string pState);

	RECT		GetFrame(Object * pObject);
	D3DXVECTOR2 GetTransition(Object * pObject);
	D3DXVECTOR2 GetBasePoint(Object * pObject);

	vector<int> GetFrameCycle(Object * pObject);
};