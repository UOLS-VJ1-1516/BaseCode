#pragma once
#include "GameObject.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameObject
{
public:
	Player();
	~Player();
	void draw(SDL_Renderer* lRender);
	void draw();
	void load(const LoadPar* lPar);
	void load(float x, float y, int width, int height, std::string texid);
	void update();
	void clean();
};
#endif PLAYER_H