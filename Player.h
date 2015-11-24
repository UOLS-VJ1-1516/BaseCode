#pragma once
#include "GameObject.h"
#include "Params.h"
#include "InputHandler.h"

class Player : public GameObject {
public:

	Player();
	~Player();
	void draw();
	void load(const Params* pParams);
	void update();
	void clean();
};
