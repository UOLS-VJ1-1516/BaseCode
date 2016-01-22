#pragma once
#include "CollisionObject.h"
#ifndef STATICOBJECTS_H
#define STATICOBJECTS_H

class StaticObjects : public CollisionObject
{
public:
	StaticObjects();
	~StaticObjects();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	void onCollsion(GameObject* other);
	void drawRotation(int angle);
	static GameObject * Create() { return new StaticObjects(); }
};

#endif STATICOBJECTS_H