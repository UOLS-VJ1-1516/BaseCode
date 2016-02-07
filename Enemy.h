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
	static GameObject * Create() { return new Enemy(); }
	void stopX(int);
	void stopY(int);
	void onCollision(GameObject* go);
private:
	float myvelocity;
};

#endif ENEMY_H