#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {

};

TextureManager::~TextureManager() {
	m_imgSurface = NULL;
	m_textureMap.clear();
}

bool TextureManager::load(const char* fileName, const char* key, SDL_Renderer* m_pRenderer) {
	//m_imgSurface = SDL_LoadBMP(fileName);
	m_imgSurface = IMG_Load(fileName);
	if (!m_imgSurface) {
		return 1;
	}

	SDL_SetColorKey(m_imgSurface, 1, SDL_MapRGB(m_imgSurface->format, 255, 255, 255));

	m_textureMap[*key] = SDL_CreateTextureFromSurface(m_pRenderer, m_imgSurface);
	SDL_FreeSurface(m_imgSurface);

	return 0;
};

void TextureManager::draw(const char* key, int x, int y, int width, int height, SDL_Renderer* m_pRenderer, SDL_RendererFlip m_pFlip) {
	SDL_RenderClear(m_pRenderer);

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = width;
	srcrect.h = height;

	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = width;
	dstrect.h = height;

	SDL_RenderCopyEx(m_pRenderer, m_textureMap[*key], &srcrect, &dstrect, 0, 0, m_pFlip);
};

void TextureManager::drawFrame(const char* key, int x, int y, int width, int height, int currentFrame, int currentRow, SDL_Renderer* m_pRenderer, SDL_RendererFlip m_pFlip) {
	srcrect.x = currentFrame * width;
	srcrect.y = currentRow * height;
	srcrect.w = width;
	srcrect.h = height;

	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = width;
	dstrect.h = height;

	SDL_RenderCopyEx(m_pRenderer, m_textureMap[*key], &srcrect, &dstrect, 0, 0, m_pFlip);
};

void TextureManager::drawTileset(const char* key, int margin, int spacing, int x, int y, int width, int height, int currentRow,
	int currentFrame, SDL_Renderer *pRenderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[*key], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}

void TextureManager::clearFromTextureMap(const char * id){
	m_imgSurface = NULL;
	m_textureMap.erase(*id);
};