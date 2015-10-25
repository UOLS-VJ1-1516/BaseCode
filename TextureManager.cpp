#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};

//Cargar imagenes
bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer* pRenderer) {
	//Cargar fichero BMP
	s_surface = SDL_LoadBMP(fileName);

	//dejar claro color fondo i transparencias
	SDL_SetColorKey(s_surface, 1, SDL_MapRGB(s_surface->format, 255, 0, 255));

	//textura.
	s_texture = SDL_CreateTextureFromSurface(pRenderer, s_surface);

	//Gaurdamos txtura
	m_textureMap[*id] = s_texture;

	return true;
};

void TextureManager::draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.x = 0;
	TextureManager::SrcR.y = 0;
	TextureManager::SrcR.w = width;
	TextureManager::SrcR.h = height;

	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {

	//Pasamos frame
	TextureManager::SrcR.x = currentFrame*width;
	TextureManager::SrcR.y = currentRow*height;
	TextureManager::SrcR.w = width;
	TextureManager::SrcR.h = height;

	//Pintar
	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

//Guardar tamaño sprite
void TextureManager::setSizeFrames(const char* id, int w, int h) {
	m_textureSizes[*id][0] = w;
	m_textureSizes[*id][1] = h;
}

TextureManager::~TextureManager() {

};


