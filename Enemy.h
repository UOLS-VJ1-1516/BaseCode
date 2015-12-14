#pragma once
#include "GameObject.h"
#include "textureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	bool dreta = true;
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	static GameObject * Create() { return new Enemy(); }
};
