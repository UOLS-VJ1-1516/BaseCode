#pragma once
#include "CollisionObject.h"
#include "Vector2D.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public CollisionObject
{
public:
	Player();
	~Player();
	void draw(SDL_Renderer* lRender);
	void draw();
	void load(const LoadPar* lPar);
	void load(int x, int y, int width, int height, std::string texid);
	void update();
	void clean();
	static GameObject * Create() { return new Player(); }
	int Player::Miraquepulsa();

};
#endif PLAYER_H