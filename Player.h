#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "LoaderParams.h"

class Player : public GameObject
{
	int spriteNum;
public:
	Player();
	~Player(); //**NUNCA pongas {} aquí, esto es la cabecera.
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();

};
#endif