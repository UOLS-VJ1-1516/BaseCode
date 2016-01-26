#pragma once
#include "CollisionObject.h"
#ifndef STATICOBJECT_H
#define STATICOBJECT_H

class StaticObject : public CollisionObject
{
public:
	StaticObject();
	~StaticObject();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	void onCollision(GameObject* other);
	static GameObject * Create() { return new StaticObject(); }
};

#endif STATICOBJECT_H
