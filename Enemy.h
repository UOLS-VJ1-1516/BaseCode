#pragma once
#include "CollisionObject.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public CollisionObject
{
public:
	Enemy();
	~Enemy();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void update(int width);
	void onCollsion(GameObject* other);
	static GameObject * Create() { return new Enemy(); }
};

#endif ENEMY_H