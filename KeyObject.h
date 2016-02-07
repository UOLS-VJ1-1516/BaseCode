#pragma once
#include "CollisionObject.h"
#ifndef KEYOBJECT_H
#define KEYOBJECT_H

class KeyObject : public CollisionObject
{
public:
	KeyObject();
	~KeyObject();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void update(int width);
	void clean();
	void stopX(int);
	void stopY(int);
	void drawRotation(int angle);
	static GameObject * Create() { return new KeyObject(); }
	void onCollision(GameObject* go);
};

#endif KEYOBJECT_H
