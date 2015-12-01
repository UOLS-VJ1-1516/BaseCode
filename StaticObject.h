#pragma once

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject {
public:
	StaticObject();
	~StaticObject();

	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	static GameObject* Create() { return new StaticObject(); }
};

#endif