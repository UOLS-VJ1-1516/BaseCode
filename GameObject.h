#pragma once
#include "SDL.h"
#include "game.h"
#include "TextureManager.h"
#include "LoaderParams.h"

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
		int m_x;
		int m_y;
		int m_spriteNum;
		int numRow;
		char* m_textureID;
		
};