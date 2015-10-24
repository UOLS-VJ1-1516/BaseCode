#pragma once
#include "TextureManger.h"
#include "SDL_image"
#include "SDL.h"


TextureManager* TextureManager::s_pInstance = 0;
SDL_Surface*img;
SDL_Texture*texture;
SDL_Point*center;
SDL_Rect inicio;
SDL_Rect dest;

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

	

	inicio.x = x;
	inicio.y = y;
	inicio.w = width;
	inicio.h = height;
	dest.h = height;
	dest.w = width;
	dest.x = x;
	dest.y = y;

	SDL_RenderCopyEx(pRender, m_pTextureMap[id], &inicio, &dest, 0, center, flip);

}

void drawFrame(char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame,
	SDL_Renderer* pRender, SDL_RendererFlip flip) {

	inicio.x = (currentFrame*width);
	inicio.y = height*(currentRow - 1);
	inicio.w = width;
	inicio.h = height;


	dest.x = x;
	dest.y = y - (height - 2);
	dest.w = width;
	dest.h = height;

	SDL_RenderCopyEx(pRender, m_pTextureMap[id], &inicio, &dest, 0, 0, flip);


}