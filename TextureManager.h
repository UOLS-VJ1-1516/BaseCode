#pragma once
#include "SDL.h"
#include "map"


class TextureManager {

	/*
	SDL_Surface textureSurface;
	SDL_Texture* texture;
	SDL_Rect  rectanguloFuente;
	SDL_Rect  rectanguloDestino;

	*/

private:
	TextureManager();
public:
	static TextureManager* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	~TextureManager();

	//declaramos las funciones
	bool load(const char* fileName, const char* id, SDL_Renderer *m_pRenderer);
	void draw(const char* id, int x, int y, int width, int height, SDL_Renderer*pRender, SDL_RendererFlip flip);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);

	static TextureManager* s_pInstance;
	std::map<char, SDL_Texture*>m_pTextureMap;
	std::map<char, int[2] > m_textureSizes;
	SDL_Surface*img;
	SDL_Texture*texture;
	SDL_Point*center;
	SDL_Rect rectanguloFuente;
	SDL_Rect rectanguloDestino;
	

	
};
