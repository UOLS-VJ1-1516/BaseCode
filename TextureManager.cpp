#include "TextureManager.h"
//#define witdh 624

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};

bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer* pRenderer) {
	s_surface = SDL_LoadBMP(fileName);
	SDL_SetColorKey(s_surface, 1, SDL_MapRGB(s_surface->format, 255, 0, 255));
	s_texture = SDL_CreateTextureFromSurface(pRenderer, s_surface);

	m_textureMap[*id] = s_texture;

	return true;
};

void TextureManager::draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.x = 0;
	TextureManager::SrcR.y = 0;
	TextureManager::SrcR.w = m_textureSizes[*id][0];
	TextureManager::SrcR.h = m_textureSizes[*id][1];

	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.x = currentFrame*m_textureSizes[*id][0];
	TextureManager::SrcR.y = currentRow*m_textureSizes[*id][1];
	TextureManager::SrcR.w = m_textureSizes[*id][0];
	TextureManager::SrcR.h = m_textureSizes[*id][1];

	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

void TextureManager::setSizeFrames(const char* id, int w, int h) {
	m_textureSizes[*id][0] = w;
	m_textureSizes[*id][1] = h;
}

TextureManager::~TextureManager(){
	
};


