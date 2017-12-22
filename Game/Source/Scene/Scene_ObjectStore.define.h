#pragma once
#define Each Each
#define _ _

#define EachGround()					\
	Add_Ground(Bar);					\
	Add_Ground(Rope);					\
	Add_Ground(Square);					\
	Add_Ground(Horizontal);				\
	Add_Ground(Stairs_slash);			\
	Add_Ground(Stairs_backslash);		\
										\
	Add_Ground(_Square);				\
	Add_Ground(_Stairs_slash);			\
	Add_Ground(_Stairs_backslash);

#define EachEnemy(Method)				\
	Method(Enemy, Assassin);			\
	Method(Enemy, Circus);				\
	Method(Enemy, Fat);					\
	Method(Enemy, Pirates);				\
	Method(Enemy, Straw);				\
	Method(Enemy, Thin);

#define EachStatic(Method)				\
	Method(Static, Abubonus);			\
	Method(Static, Apple);				\
	Method(Static, Block_Drop);			\
	Method(Static, Black_Magic_Lamp);	\
	Method(Static, Extra_Health);		\
	Method(Static, Genie_Bonus);		\
	Method(Static, Restart_Point);		\
	Method(Static, Spend_These);		\
	Method(Static, Stick);

#define EachNPC(Method)					\
	Method(NPC, Camel);					\
	Method(NPC, Stall);					\
	Method(NPC, Peddler);

#define EachObject(Method)				\
	EachEnemy(Method)					\
	EachStatic(Method)					\
	EachNPC(Method)

#define Add_Unit(type, name)											\
json j_##type##_##name = block[#type"_"#name];							\
for (auto& s : j_##type##_##name) {										\
	m##type##_##name.push_back(											\
		make_pair(														\
			RECT{s[0],s[1],s[2],s[3]},									\
			nullptr														\
		)																\
	);																	\
}

#define Add_Ground(kind)												\
json j_##kind = block[#kind];											\
for (auto& s : j_##kind) {												\
	m##kind.push_back(													\
		RECT{s[0],s[1],s[2],s[3]}										\
	);																	\
}

//# Object_UpdateEvent
#define Object_UpdateEvent(type, name)									\
for (auto &unit : m##type##_##name) {									\
	if (isIntersect(unit.first, camera)) {								\
		if (unit.second == nullptr || unit.second == NULL) {			\
			unit.second = new Object_Unit_##type##_##name(unit.first);	\
		}																\
		unit.second->ObjectUpdateEvent(dt);								\
	}																	\
	else if (unit.second != NULL) {										\
		delete unit.second;												\
		unit.second = NULL;												\
	}																	\
}

//# Delete
bool ifMarkedDelete(const pair<RECT, Object *>& p) {
	if (p.second == NULL || p.second == nullptr) return false;
	else if (p.second->mIsMarkedDelete) {
		delete p.second;
		return true;
	}
	else return false;
}

bool ifMarkedDeleteLost(const Object* o) {
	if (o->mIsMarkedDelete) {
		delete o;
		return true;
	}
	else return false;
}

#define Object_RemoveMarkedDelete_(type, name) m##type##name.remove_if(ifMarkedDelete);
#define Object_RemoveMarkedDelete(type, name) Object_RemoveMarkedDelete_(type, _##name)

#define ToEachMethod(object, type, name)					\
ObjectCheckCollisionWith##type##Each(object, &m##type##_##name)

#define Object_CheckCollisionWithEnemy_(type, name) ObjectCheckCollisionWithEnemyEach(pPlayer, &m##type##name)
#define Object_CheckCollisionWithEnemy(type, name) Object_CheckCollisionWithEnemy_(type, _##name)

#define Object_Render(type, name)									\
for (auto &b : m##type##_##name) {	   									\
	if (b.second != NULL) {		   									\
		b.second->ObjectRender(dt);									\
	}							   									\
}

//# GetDistance
#define Check_Square(v, value) 										\
long v = value; 													\
if(v >= 0 && (v < out.v || out.v == -1)) out.v = v

#define Check_Squares(x,y) {										\
	Check_Square(x, u.x - b->y);									\
	Check_Square(y, b->x - u.y);									\
}

#define Check_Stair(uy)												\
if (b->bottom >= u.bottom) {										\
	LONG b_height = b->bottom - b->top;								\
	LONG b_weight = b->right - b->left;								\
	LONG u_y = max(uy, 0);											\
	LONG u_x = min(b_height * u_y / b_weight, b_height);			\
	out.bottom = min(out.bottom, (b->bottom - u_x) - u.bottom);		\
}

#define If_Object(x,y)	if(u.x > b.y && b.x > u.y)
#define If_Pointer(x,y)	if(u.x > b->y && b->x > u.y)
#define Filter_Ground(var)											\
for (auto &b : m##var) {											\
	If_Object(right, left) 		top_bottom.push_back(&b);			\
	If_Object(bottom, top)		left_right.push_back(&b);			\
}

#define Filter_Ground_LeftRight(var)								\
for (auto &b : m##var) {											\
	If_Object(right, left) 		top_bottom.push_back(&b);			\
}

#define Clear_Filter()												\
left_right.clear();													\
top_bottom.clear();