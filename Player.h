#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "SDL.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	void incrementAccelerationX();
	void decrementAccelerationX();
private:
	SDL_RendererFlip m_Orientation;
	Vector2D m_lastPosition;
	void Stop(int position_x);
};

#endif