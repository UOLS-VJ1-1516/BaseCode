#pragma once
#include "TextureManager.h"
#include "game.h"

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager() {

}


TextureManager::~TextureManager() {

}

bool TextureManager::load(char* fileName, char* id, SDL_Renderer* pRenderer) {

	//cargamos la textura
	textura = IMG_LoadTexture(pRenderer, fileName);

	return true;
}

void TextureManager::drawFrame(char* id, int x, int y, int width, int height, int
	currentRow, int currentFrame, SDL_Renderer* pRender) {

	//x y y es el rectangulo que coges en el spritesheet
	srcrect.x = currentFrame * 125;
	srcrect.y = currentRow;
	srcrect.w = width;
	srcrect.h = height;

	dstrect.x = 1600 / 2 - width;
	dstrect.y = 900 / 2 - height;
	dstrect.w = width;
	dstrect.h = height;

	SDL_RenderCopy(pRender, textura, &srcrect, &dstrect);
}