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

		virtual void load(const LoaderParams* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();
		void incrementAcceleration();
		void decrementAcceleration();
		static GameObject* Create() { return new Player(); }

};

#endif