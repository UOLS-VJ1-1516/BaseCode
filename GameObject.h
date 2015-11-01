#pragma once
#include "SDL.h"
#include "game.h"
#include "TextureManager.h"

class GameObject
{

	public:
		GameObject();
		~GameObject();

		std::string m_textureID;
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		int m_x;
		int m_y;
		int spriteNum;
		int numRow;

		void load(int x, int y, int width, int height, std::string textureID);
		void draw();
		void update();
		void clean();
		
};