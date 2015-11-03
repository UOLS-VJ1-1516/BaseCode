#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
	public:
		Enemy();
		~Enemy();
		void load(const LoaderParams* pParams);
		void draw();
		void update();
		void clean();
};
