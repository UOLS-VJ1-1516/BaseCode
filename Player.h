#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
};