#pragma once
#include "GameObject.h"

class enemy : public GameObject
{
public:
	enemy();
	~enemy();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
};