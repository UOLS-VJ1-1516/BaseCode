#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"

class Player : public GameObject {
public:
	Player();
	~Player();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
};
#endif