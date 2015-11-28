#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "LoaderParams.h"

class Enemy : public GameObject {
public:
	Enemy();
	~Enemy();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
};
#endif