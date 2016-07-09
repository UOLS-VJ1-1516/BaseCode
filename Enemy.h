#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "LoaderParams.h"

class Enemy : public GameObject
{
	public:

		Enemy();
		~Enemy();

		virtual void load(const LoaderParams* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();

		//static GameObject* Create() { return new Enemy(); }

	private:

		Vector2D m_position;
		Vector2D m_velocity;
		Vector2D m_maxVelocity;
		Vector2D m_acceleration;
		Vector2D m_friction;

		int m_x;
		int m_y;
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		int m_sprite;
		const char* m_textureID;

		SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
};

#endif ENEMY_H