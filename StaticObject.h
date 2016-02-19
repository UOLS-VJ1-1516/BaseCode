#pragma once

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "CollisionObject.h"

class StaticObject : public CollisionObject {
public:
	StaticObject();
	~StaticObject();

	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void onCollision(GameObject* other);
	static GameObject* Create() { return new StaticObject(); }
};

#endif