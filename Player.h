#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "textureManager.h"
#include "game.h"

class Player : public GameObject
{

	public:
		
		Player();
		~Player();

		virtual void load(const LoaderParams* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();

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

		const LoaderParams* Params;

		SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

};

#endif PLAYER_H