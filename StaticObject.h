#pragma once

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject {
public:
	StaticObject();
	~StaticObject();

	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
};

#endif