#pragma once
#include "GameObject.h"
#ifndef STATICOBJECT_H
#define STATICOBJECT_H

class StaticObject : public GameObject
{
public:
	StaticObject();
	~StaticObject();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
};

#endif STATICOBJECT_H
