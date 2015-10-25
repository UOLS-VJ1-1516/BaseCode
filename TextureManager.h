#pragma once
#include "SDL.h"
#include "map"

class TextureManager
{
	
public:
	~TextureManager();
	TextureManager();
	static TextureManager* s_pInstance;
	SDL_Surface* s_surface;
	SDL_Texture* s_texture;
	SDL_Rect SrcR;
	SDL_Rect DestR;

	std::map<char, SDL_Texture* > m_textureMap;
	std::map<char, int[0] > m_textureSizes;

	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}

	bool load(const char* fileName, const char* id, SDL_Renderer* pRenderer);
	void draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender,SDL_RendererFlip flip);
	void setSizeFrames(const char* id, int width, int height);
};