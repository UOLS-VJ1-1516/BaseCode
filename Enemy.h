#pragma once
#include "GameObject.h"

class Enemy : public GameObject
 {
	public:
		Enemy();
		~Enemy();
		void draw(SDL_Renderer* pRender);
		void draw();
		void load(const LoadPar* pParams);
		void load(int x, int y, int width, int height,std::string texid);
		void update();
		void clean();
		};
#pragma once