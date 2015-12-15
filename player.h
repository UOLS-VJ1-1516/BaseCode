#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();

	static GameObject* Create() { return new Player(); }


private:
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	
};