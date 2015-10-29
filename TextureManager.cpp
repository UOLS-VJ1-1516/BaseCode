#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

bool TextureManager::load(char* fileName, char* id, SDL_Renderer *m_pRenderer) {

	img = SDL_LoadBMP(fileName);

	SDL_SetColorKey(img, 1, SDL_MapRGB(img->format, 255, 0, 255));
	texture = SDL_CreateTextureFromSurface(m_pRenderer, img);
	//SDL_FreeSurface(img);
	m_pTextureMap[*id] = texture;
	return true;


	
}

void TextureManager::draw(char* id, int x, int y, int width, int height,
	SDL_Renderer*pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {

	inicio.x = 0;
	inicio.y = 0;
	inicio.w = width;
	inicio.h = height;
	dest.h = height;
	dest.w = width;
	dest.x = 50;
	dest.y = 100;

	SDL_RenderCopyEx(pRender, m_pTextureMap[*id], &inicio, &dest, 0, center, flip);

}

void TextureManager::drawFrame(char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame,
	SDL_Renderer* pRender, SDL_RendererFlip flip) {

	inicio.x = currentFrame*width;//alto y anchod de los frames
	inicio.y = height*currentRow;//fila 0
	inicio.w = width;
	inicio.h = height;


	//dest.x = x;
	//dest.y = y - (height - 2);
	dest.x = x;
	dest.y = y;
	dest.w = width;

	
	dest.h = height;SDL_RenderCopyEx(pRender, texture, &inicio, &dest, 0, 0, flip);


}