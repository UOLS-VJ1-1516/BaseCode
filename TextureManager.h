#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL.h"
#include "map"
#include <SDL_image.h>



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

	bool load(const char* fileName, const char* id, SDL_Renderer* pRenderer);
	void draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender,
		SDL_RendererFlip flip);

private:
	static TextureManager* s_pInstance;
	std::map<char, SDL_Texture* > m_textureMap;
	SDL_Surface* s_surface;
	SDL_Texture* s_texture;
	SDL_Rect SrcR;
	SDL_Rect DestR;
};

#endif