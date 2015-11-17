#include "TextureManager.h"
#include "game.h"
#include "stdio.h"
#include "SDL_image.h"

// Instancia de TextureManager
TextureManager* TextureManager::s_pInstance = 0;

// Constructor y destructor
TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

// Carrgar Texturas
bool TextureManager::load(char* fileName, const char* id, SDL_Renderer* pRenderer) {

	SDL_Surface* pTempSurface = IMG_Load(fileName);
	if (pTempSurface == 0)
	{
		return false;
	}
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRender, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
};

void TextureManager::setFrame(const char* id, int x, int y, int w, int h) {
	m_textureMap[id] = texture;
	m_texturePositions[*id][0] = x;
	m_texturePositions[*id][1] = y;
	m_textureSizes[*id][0] = w;
	m_textureSizes[*id][1] = h;
}
