#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "map"

class TextureManager
{
	public:
		TextureManager();

		static TextureManager* Instance()
		{
			if (s_pInstance == 0)
			{
				s_pInstance = new TextureManager();
			}
			return s_pInstance;
		}
		~TextureManager();

		bool load(char* fileName, const char* id, SDL_Renderer* pRenderer);
		void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
		void setFrame(const char* id, int x, int y, int width, int height);

		static TextureManager* s_pInstance;
		SDL_Texture* texture;
		SDL_Rect SrcR;
		SDL_Rect DestR;
		std::map<char, SDL_Texture* > m_textureMap;
		std::map<char, int[2] > m_texturePositions;
		std::map<char, int[2] > m_textureSizes;
};
