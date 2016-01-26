#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "CollisionObject.h"

class Enemy : public CollisionObject
{
public:
	Enemy();
	~Enemy();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	void onCollision(GameObject* other);
	static GameObject * Create() { return new Enemy(); }
};

#endif ENEMY_H