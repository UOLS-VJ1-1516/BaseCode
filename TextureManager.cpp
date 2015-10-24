#pragma once
#include "TextureManger.h"
#include "SDL.h"

TextureManager* TextureManager::s_pInstance = 0;
SDL_Surface*img;
SDL_Texture*texture;
SDL_Point*center;

bool load(char* fileName, char* id, SDL_Renderer *m_pRenderer) {

	return true;
}

void draw(char* id, int x, int y, int width, int height,
	SDL_Renderer*pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {

}

void drawFrame(char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame,
	SDL_Renderer* pRender, SDL_RendererFlip = SDL_FLIP_NONE) {

}