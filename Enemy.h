#pragma once
#include "GameObject.h"

//Clase para crear un game object del tipo enemigo
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