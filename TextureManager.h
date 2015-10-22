#pragma once
#include "SDL_image.h"
#include "map"


class TextureManager {

public:

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRender, SDL_RendererFlip flip);

	void drawFrame(std::string id, int x, int y, int width, int height, int
		currentRow, int currentFrame, SDL_Renderer* pRender,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	


	public:
		static TextureManager* Instance()
		{
			if (s_pInstance == 0)
			{
				s_pInstance = new TextureManager();
			}
			return s_pInstance;
		}
		TextureManager::~TextureManager() {

		}

		TextureManager::TextureManager() {

		}
	
	private:
		static TextureManager* s_pInstance;

};