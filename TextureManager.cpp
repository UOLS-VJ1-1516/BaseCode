#include "SDL_image.h"
#include "TextureManager.h"
#include "map"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};

bool TextureManager::load(const char* fileName, std::string id, SDL_Renderer* pRenderer) {

	SDL_Surface* pTempSurface = IMG_Load(fileName);

	if (pTempSurface == 0) {

		return false;
	}
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}

void TextureManager::draw(const char* id, int x, int y, int width, int height, SDL_Renderer * pRender, SDL_RendererFlip flip)
{

	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;
	destRect.w = width;
	destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRender, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);

}

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * pRender, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = width;
	destRect.w = width;
	srcRect.h = height;
	destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRender, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);

}
