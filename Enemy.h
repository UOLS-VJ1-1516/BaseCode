#pragma once
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy();
	~Enemy();

	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();

private:
	SDL_RendererFlip flip = SDL_FLIP_NONE;

};