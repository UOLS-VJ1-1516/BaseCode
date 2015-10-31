#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};


bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer *m_pRenderer) {

	img = SDL_LoadBMP(fileName);

	SDL_SetColorKey(img, 1, SDL_MapRGB(img->format, 255, 0, 255));
	texture = SDL_CreateTextureFromSurface(m_pRenderer, img);
	//SDL_FreeSurface(img);
	m_pTextureMap[*id] = texture;
	return true;


	
}

void TextureManager::draw(const char* id, int x, int y, int width, int height,
	SDL_Renderer*pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {
	TextureManager::inicio.w = m_textureSizes[*id][0];
	TextureManager::inicio.h = m_textureSizes[*id][1];
	TextureManager::inicio.w = width;
	TextureManager::inicio.h = height;
	/*inicio.x = 0;
	inicio.y = 0;
	inicio.w = width;
	inicio.h = height;
	dest.h = height;
	dest.w = width;
	dest.x = 50;
	dest.y = 100;*/
	TextureManager::dest.x = x;
	TextureManager::dest.y = y;
	TextureManager::dest.w = width;
	TextureManager::dest.h = height;

	SDL_RenderCopyEx(pRender, m_pTextureMap[*id], &inicio, &dest, 0, center, flip);

}

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame,
	SDL_Renderer* pRender, SDL_RendererFlip flip) {

	TextureManager::inicio.x = currentFrame*m_textureSizes[*id][0];
	TextureManager::inicio.y = currentRow*m_textureSizes[*id][1];
	TextureManager::inicio.w = m_textureSizes[*id][0];
	TextureManager::inicio.h = m_textureSizes[*id][1];
	TextureManager::dest.x = x;
	TextureManager::dest.y = y;
	TextureManager::dest.w = width;
	TextureManager::dest.h = height;
	
	/*dest.x = x;
	dest.y = y;
	dest.w = width;
	dest.h = height;*/

	SDL_RenderCopyEx(pRender, texture, &inicio, &dest, 0, 0, flip);


}
void TextureManager::setSizeFrames(const char* id, int w, int h) {
	m_textureSizes[*id][0] = w;
	m_textureSizes[*id][1] = h;
};