#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;



TextureManager::TextureManager() {

};
TextureManager::~TextureManager() {

};

bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer *m_pRenderer) {

	img = SDL_LoadBMP(fileName);
	texture = SDL_CreateTextureFromSurface(m_pRenderer, img);
	m_pTextureMap[*id] = texture;

	return true;
}

void TextureManager::draw(const char* id, int x, int y, int width, int height,
	SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {



	TextureManager::rectanguloFuente.w = 0;
	TextureManager::rectanguloFuente.h = 0;
	TextureManager::rectanguloFuente.w = width;//anchura del cuadro
	TextureManager::rectanguloFuente.h = height;//altura del cuadro
	



	TextureManager::rectanguloDestino.x = x;
	TextureManager::rectanguloDestino.y = y;
	TextureManager::rectanguloDestino.w = width;
	TextureManager::rectanguloDestino.h = height;

	SDL_RenderCopyEx(pRender, m_pTextureMap[*id], &rectanguloFuente, &rectanguloDestino, 0, center, flip);

}

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {



	TextureManager::rectanguloFuente.x=currentFrame*width;
	TextureManager::rectanguloFuente.y = height*currentRow;
	TextureManager::rectanguloFuente.w = width;
	TextureManager::rectanguloFuente.h = height;
	



	TextureManager::rectanguloDestino.x = x;
	TextureManager::rectanguloDestino.y = y;
	TextureManager::rectanguloDestino.w = width;
	TextureManager::rectanguloDestino.h = height;

	SDL_RenderCopyEx(pRender, m_pTextureMap[*id], &rectanguloFuente, &rectanguloDestino, 0, 0, flip);
}
