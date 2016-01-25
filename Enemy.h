#pragma once
#include "CollisionObject.h"

//Clase para crear un game object del tipo enemigo
class Enemy : public CollisionObject
{
public:
	Enemy();
	~Enemy();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	static GameObject * Create() { return new Enemy(); }
};