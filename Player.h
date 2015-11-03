#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDL.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameObject
{
public:
	Player();
	~Player();
	//void load(const LoaderParams* pParams);
	void load(int x, int y, int width, int height, const char* textureID);
	void draw();
	void update();
	void clean();
};
#endif PLAYER_H
