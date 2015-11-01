#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"


class Player : public GameObject
{

public:
	Player();
	~Player();
	void draw(SDL_Renderer* lRender);
	void draw();
	bool load(const LoadPar* lPar);
	bool load(int x, int y, int width, int height, char* texid);
	void update();
	void clean();

};
#endif PLAYER_H