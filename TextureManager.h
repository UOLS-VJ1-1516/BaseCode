#pragma once
#include "SDL.h"
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

	bool load(char* fileName, char* id, SDL_Renderer *m_pRenderer);
	void draw(char* id, int x, int y, int width, int height,
		SDL_Renderer*pRender, SDL_RendererFlip flip);

	void drawFrame(char* id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRender, SDL_RendererFlip flip);

private:
	static TextureManager* s_pInstance;
	std::map<char, SDL_Texture*>m_pTextureMap;
	SDL_Surface*img;
	SDL_Texture*texture;
	SDL_Point*center;
	SDL_Rect inicio;
	SDL_Rect dest;
};