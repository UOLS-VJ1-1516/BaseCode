
#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "map"


	class TextureManager
	{
		public:
		TextureManager::TextureManager() {  //Constructor

		}
		TextureManager::~TextureManager() {

		}
	public:
	bool load(char* fileName, std::string  id, SDL_Renderer* pRenderer);
		void draw(std::string, int x, int y, int width, int height,
			SDL_Renderer* pRender, SDL_RendererFlip flip);
		void drawFrame(std::string, int x, int y, int width, int height, int
			currentRow, int currentFrame, SDL_Renderer* pRender,
			SDL_RendererFlip flip = SDL_FLIP_NONE);
		
		static TextureManager* Instance()
		{
			if (s_pInstance == 0)
			{
				s_pInstance = new TextureManager();
			}
			return s_pInstance;
		}

		std::map<std::string, SDL_Texture*> m_textureMap;

	private:
		static TextureManager* s_pInstance;

	};

#endif TEXTUREMANAGER_H