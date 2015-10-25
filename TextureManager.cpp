#include "TextureManager.h"


TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager()
{ };

TextureManager::~TextureManager()
{ };

bool TextureManager::load(char* fileName, char* id, SDL_Renderer* m_pRenderer) {
	image = SDL_LoadBMP(fileName);
	SDL_SetColorKey(image, true, SDL_MapRGB(image->format, 255, 255, 255));
	texture = SDL_CreateTextureFromSurface(m_pRenderer, image);
	m_textureMap[*id] = texture;
	
	return true;
}

void TextureManager::draw(char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {

	Src.x = 0;
	Src.y = 0;
	Src.w = width;
	Src.h = height;

	Dest.x = 58;
	Dest.y = 38;
	Dest.w = width;
	Dest.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &Src, &Dest, 0, 0, flip);


}

void TextureManager::drawFrame(char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {

	Src.x = currentFrame * width;
	Src.y = currentRow * height;
	Src.w = width;
	Src.h = height;

	Dest.x = 640 / 2 - width / 2;
	Dest.y = 480 / 2 - height / 2;
	Dest.w = width;
	Dest.h = height;

	SDL_RenderCopyEx(pRender, texture, &Src, &Dest, 0, 0, flip);

};