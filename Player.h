#pragma once
#include "GameObject.h"
#include "LoaderParams.h"

class Player : public GameObject
{
	int spriteNum;
public:
	Player() {};
	~Player() {};
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	
};
