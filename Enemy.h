#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy();
	~Enemy();

	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	static GameObject* Create() { return new Enemy(); }
};

#endif