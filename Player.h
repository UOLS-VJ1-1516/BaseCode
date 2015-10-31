#pragma once
#include "GameObject.h"
#ifndef PLAYER_H
#define PLAYER_H


class Player : public GameObject
{
public:
	Player();
	~Player();
	void draw(SDL_Renderer* pRender);
	void draw();
	void load(const LoaderParams* pParams);
	void load(int x, int y, int width, int height,
		std::string textureID);
	void update();
	void clean();
};
#endif PLAYER_H
