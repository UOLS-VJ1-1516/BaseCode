#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void draw(SDL_Renderer* pRender);
	void load(const LoaderParams* pParams);
	void update();
	void clean();

private:
	SDL_RendererFlip flip = SDL_FLIP_NONE;

};