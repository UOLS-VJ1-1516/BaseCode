#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "CollisionObject.h"

class Enemy : public CollisionObject {
public:
	Enemy();
	~Enemy();

	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void onCollision(GameObject* other);
	static GameObject* Create() { return new Enemy(); }
};

#endif