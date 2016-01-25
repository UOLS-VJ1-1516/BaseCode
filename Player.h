#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "CollisionObject.h"
#include "SDL.h"

class Player : public CollisionObject {
	private:
		SDL_RendererFlip m_orientation;
		Vector2D m_lastStop;
		void stopX(int xPos);
		void stopY(int yPos);
		bool m_jump = false;
	
	public:
		Player();
		~Player();

		virtual void load(const LoaderParams* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();
		void onCollision(GameObject* other);
		void incrementAccelerationX();
		void decrementAccelerationX();
		void incrementAccelerationY();
		void decrementAccelerationY();
		static GameObject* Create() { return new Player(); }
		void jump();

};

#endif