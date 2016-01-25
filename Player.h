#pragma once
#include "CollisionObject.h"
#include "textureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "SDL.h"
#include "LoaderParams.h"

class Player : public CollisionObject
{
public:
	Player();
	virtual~Player();
	bool dreta = true;
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Player(); }
};