#pragma once
#include "CollisionObject.h"
#include "textureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"

class Muerte : public CollisionObject
{
public:
	Muerte();
	~Muerte();
	bool dreta = true;
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	static GameObject * Create() { return new Muerte(); }
};
