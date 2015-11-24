#pragma once
#include "GameObject.h"
#include "Params.h"

class Enemy : public GameObject {
public:



	Enemy();
	~Enemy();
	void draw();
	void load(const Params* pParams);
	void update();
	void clean();



};
