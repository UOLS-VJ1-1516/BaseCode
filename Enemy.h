#pragma once
#include "CollisionObject.h"

class Enemy : public CollisionObject {
public:
	Enemy();
	~Enemy();

	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();

	static GameObject* Create() { return new Enemy(); }

private:
	SDL_RendererFlip flip = SDL_FLIP_NONE;

};