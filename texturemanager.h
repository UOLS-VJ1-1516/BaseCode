#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "SDL.h"
#include "SDL_image.h"
#include "map"

class TextureManager
{
	private:
		TextureManager();
	public:
		static TextureManager* Instance()
		{
			if (s_pInstance == 0)
			{
				s_pInstance = new TextureManager();
			}
			return s_pInstance;
		}
		~TextureManager();

		bool load(char* fileName, char* id, SDL_Renderer* pRenderer);
		void draw(char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
		void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
		void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer);
		void clear(std::string id);

		std::map<std::string, SDL_Texture*> m_textureMap;

	private:
		static TextureManager* s_pInstance;

};
#endif TEXTUREMANAGER_H