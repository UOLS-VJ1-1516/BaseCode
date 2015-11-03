#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "map"

class TextureManager
{

	/*
	SDL_Surface textureSurface;
	SDL_Texture* texture;
	SDL_Rect  rectanguloFuente;
	SDL_Rect  rectanguloDestino;

	*/

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
	//~TextureManager();

	bool load(char* fileName, const char* id, SDL_Renderer* pRenderer);
	//void drawFrame(char * id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * pRender);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);

	void setFrame(const char* id, int x, int y, int width, int height);

private:
	static TextureManager* s_pInstance;
	SDL_Texture* texture;
	SDL_Rect rectanguloFuente;
	SDL_Rect rectanguloDestino;
	std::map<char, SDL_Texture* > m_textureMap;
	std::map<char, int[2] > m_texturePositions;
	std::map<char, int[2] > m_textureSizes;
};