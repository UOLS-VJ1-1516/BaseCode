#pragma once
#include "GameObject.h"
#include "textureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "SDL.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	bool dreta = true;
	SDL_Event event;
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
};