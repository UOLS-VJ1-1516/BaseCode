#pragma once
#include "GameObject.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public GameObject
 {
	public:
		Enemy();
		~Enemy();
		void draw(SDL_Renderer* lRender);
		void draw();
		void load(const LoadPar* lPar);
		void load(float x, float y, int width, int height,std::string texid);
		void update();
		void clean();
		static GameObject * Create() { return new Enemy(); }
		};
#endif ENEMY_H