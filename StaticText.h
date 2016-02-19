#pragma once

#ifndef STATICTEXT_H
#define STATICTEXT_H

#include "CollisionObject.h"

class StaticText : public CollisionObject {
public:
	StaticText();
	~StaticText();

	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void onCollision(GameObject* other);
	static GameObject* Create() { return new StaticText(); }
};

#endif