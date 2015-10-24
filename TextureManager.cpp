#pragma once
#include "TextureManger.h"
#include "SDL_image.h"
#include "SDL.h"


TextureManager* TextureManager::s_pInstance = 0;
SDL_Surface*img;
SDL_Texture*texture;
SDL_Point*center;

bool load(char* fileName, char* id, SDL_Renderer *m_pRenderer) {

	img = IMG_Load(fileName);

	if (img == 0) {
		return false;
	}
	SDL_SetColorKey(img, 1, SDL_MapRGB(img->format, 72, 104, 112));
	SDL_Texture *textura = SDL_CreateTextureFromSurface(m_pRenderer, img);
	SDL_FreeSurface(img);

	if (textura != 0) {
		m_pTextureMap[id] = texture;

		return true;
	}
	else {
		return false;
	}
}

void draw(char* id, int x, int y, int width, int height,
	SDL_Renderer*pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {

}

void drawFrame(char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame,
	SDL_Renderer* pRender, SDL_RendererFlip = SDL_FLIP_NONE) {

}