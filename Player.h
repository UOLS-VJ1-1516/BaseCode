#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDL.h"
#include "Vector2D.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameObject
{
public:
	Player();
	~Player();
	void load(const LoaderParams* ppParams);
	void draw();
	void update();
	void clean();
};
#endif PLAYER_H
