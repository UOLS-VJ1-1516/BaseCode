#pragma once
#include "GameObject.h"
#include "Vector2D.h"

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
	void load(int x, int y, int width, int height, std::string texid);
	void update();
	void clean();
	static GameObject * Create() { return new Player(); }
private:
	Vector2D m_pos;
};
#endif PLAYER_H