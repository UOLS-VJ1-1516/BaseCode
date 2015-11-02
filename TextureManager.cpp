#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {

};

bool TextureManager::load(const char* fileName, const char* key, SDL_Renderer* m_pRenderer) {
	SDL_Surface* img = SDL_LoadBMP(fileName);

	if (!img) {
		return 1;
	}

	textureMap[*key] = SDL_CreateTextureFromSurface(m_pRenderer, img);
	SDL_FreeSurface(img);

	return 0;
};

void TextureManager::draw(const char* key, int x, int y, int width, int height, SDL_Renderer* m_pRenderer, SDL_RendererFlip m_pFlip) {
	SDL_RenderClear(m_pRenderer);

	SDL_Rect srcrect, dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = width;
	srcrect.h = height;

	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = width;
	dstrect.h = height;

	SDL_RenderCopyEx(m_pRenderer, textureMap[*key], &srcrect, &dstrect, 0, 0, m_pFlip);
};

void TextureManager::drawFrame(const char* key, int x, int y, int width, int height, int currentFrame, int currentRow, SDL_Renderer* m_pRenderer, SDL_RendererFlip m_pFlip) {

	SDL_Rect srcrect, dstrect;

	srcrect.x = currentFrame * width;
	srcrect.y = currentRow * height;
	srcrect.w = width;
	srcrect.h = height;

	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = width;
	dstrect.h = height;

	SDL_RenderCopyEx(m_pRenderer, textureMap[*key], &srcrect, &dstrect, 0, 0, m_pFlip);
};