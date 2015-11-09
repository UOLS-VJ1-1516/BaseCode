#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer *m_pRenderer) {
	img = SDL_LoadBMP(fileName);
	SDL_SetColorKey(img, 1, SDL_MapRGB(img->format, 255, 0, 255));
	texture = SDL_CreateTextureFromSurface(m_pRenderer, img);
	m_pTextureMap[*id] = texture;
	return true;
}

void TextureManager::draw(const char* id, int x, int y, int width, int height,
	SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {
	TextureManager::inicio.w = 0;
	TextureManager::inicio.h = 0;
	TextureManager::inicio.w = width;
	TextureManager::inicio.h = height;
	
	TextureManager::dest.x = x;
	TextureManager::dest.y = y;
	TextureManager::dest.w = width;
	TextureManager::dest.h = height;

	SDL_RenderCopyEx(pRender, m_pTextureMap[*id], &inicio, &dest, 0, center, flip);

}

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {

	TextureManager::inicio.x=currentFrame*width;
	TextureManager::inicio.y = height*currentRow;
	TextureManager::inicio.w = width;
	TextureManager::inicio.h = height;
	
	TextureManager::dest.x = x;
	TextureManager::dest.y = y;
	TextureManager::dest.w = width;
	TextureManager::dest.h = height;

	SDL_RenderCopyEx(pRender, m_pTextureMap[*id], &inicio, &dest, 0, 0, flip);
}
