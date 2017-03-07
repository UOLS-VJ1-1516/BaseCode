#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "SDL_image.h"
#include "map"


class TextureManager {

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

	TextureManager::~TextureManager() {}


	bool load(const char* fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(const char* id, float x, float y, int width, int height,
		SDL_Renderer* pRender, SDL_RendererFlip flip);

	void drawFrame(const char* id, int x, int y, int width, int height, int
		currentRow, int currentFrame, SDL_Renderer* pRender,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void TextureManager::clearFromTextureMap(std::string id)
	{
		m_textureMap.erase(id);
	}
	
	private:
		static TextureManager* s_pInstance;
		std::map<std::string, SDL_Texture*> m_textureMap;
		SDL_Surface* s_surface;
		SDL_Texture* s_texture;

};
#endif TEXTUREMANAGER_H