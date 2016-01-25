#pragma once
#include "CollisionObject.h"
#include "textureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "SDL.h"

class Enemy : public CollisionObject
{
public:
	Enemy();
	virtual~Enemy();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Enemy(); }
	
};
