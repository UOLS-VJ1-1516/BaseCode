#pragma once
#include "SDL.h"
#include "game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{

	public:
		virtual void load(const LoaderParams* pParams) = 0;
		virtual void draw(SDL_Renderer* pRender) = 0;
		virtual void update() = 0;
		virtual void clean() = 0;

	protected:
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		char* m_textureID;
		int m_spriteNum;
		Vector2D m_position;
		Vector2D m_velocity;
		Vector2D m_maxVelocity;
		Vector2D m_acceleration;
		Vector2D m_friction;
};