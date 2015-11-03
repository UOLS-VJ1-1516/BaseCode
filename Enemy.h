#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy();
	~Enemy();

	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
};

#endif