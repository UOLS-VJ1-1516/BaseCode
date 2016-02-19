#include "TextureManager.h"


TextureManager *TextureManager::s_pInstance = 0;


TextureManager::TextureManager()
{

}

TextureManager::~TextureManager() {

}

bool TextureManager::load(std::string file, std::string id, SDL_Renderer * m_pRenderer)
{
	SDL_Surface* s_sprite = IMG_Load(file.c_str());
	SDL_SetColorKey(s_sprite, SDL_TRUE, SDL_MapRGB(s_sprite->format, 255, 255, 255));
	SDL_Texture* s_texture = SDL_CreateTextureFromSurface(m_pRenderer, s_sprite);
	SDL_FreeSurface(s_sprite);
	m_textureMap[id] = s_texture;
	return true;
}
void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer * pRender, SDL_RendererFlip flip)
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

	SDL_RenderCopyEx(pRender, m_textureMap[id],
		&srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow );
	srcRect.w = width;
	destRect.w = width;
	srcRect.h = height;
	destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id],
		&srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawTile(std::string id, int margin, int
	spacing, int x, int y, int width, int height, int currentRow,
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
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, SDL_FLIP_NONE);
}