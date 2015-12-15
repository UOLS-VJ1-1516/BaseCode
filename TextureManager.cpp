#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager() {};

TextureManager::~TextureManager() {};

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* m_pRenderer) {
	image = IMG_Load(fileName.c_str());
	SDL_SetColorKey(image, true, SDL_MapRGB(image->format, 255, 255, 255));
	texture = SDL_CreateTextureFromSurface(m_pRenderer, image);
	SDL_FreeSurface(image);
	m_textureMap[id] = texture;
	return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {

	Src.x = 0;
	Src.y = 0;
	Src.w = width;
	Src.h = height;

	Dest.x = 58;
	Dest.y = 38;
	Dest.w = width;
	Dest.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[id], &Src, &Dest, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {

	Src.x = currentFrame * width;
	Src.y = currentRow * height;
	Src.w = width;
	Src.h = height;

	Dest.x = x;
	Dest.y = y;
	Dest.w = width;
	Dest.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[id], &Src, &Dest, 0, 0, flip);
}

void TextureManager::clearTexture(std::string id) {
	m_textureMap.erase(id);
}

void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow,
	int currentFrame, SDL_Renderer *pRenderer) {

	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
};