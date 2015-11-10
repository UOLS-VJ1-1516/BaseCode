#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "SDL.h"

class Player : public GameObject {
	private:
		SDL_RendererFlip m_orientation;
		Vector2D m_lastStop;
		void stop(int xPos);
	
	public:
		Player();
		~Player();

		void load(const LoaderParams* pParams);
		void draw();
		void update();
		void clean();
		void incrementAcceleration();
		void decrementAcceleration();

};

#endif