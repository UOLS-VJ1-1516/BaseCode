#include "TextureManager.h"
//#define witdh 624

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};

bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer* pRenderer) {
	s_surface = SDL_LoadBMP(fileName);
	SDL_SetColorKey(s_surface, 0, SDL_MapRGB(s_surface->format, 255, 255, 255));
	s_texture = SDL_CreateTextureFromSurface(pRenderer, s_surface);
	
	m_textureMap[*id] = s_texture;

	return true;
};

void TextureManager::draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.x = x;
	TextureManager::SrcR.y = y;
	TextureManager::SrcR.w = width;
	TextureManager::SrcR.h = height;

	TextureManager::DestR.x = 0;
	TextureManager::DestR.y = 0;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;
	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.x = x;
	TextureManager::SrcR.y = y;
	TextureManager::SrcR.w = width;
	TextureManager::SrcR.h = height;

	TextureManager::DestR.x = 0;
	TextureManager::DestR.y = 0;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

TextureManager::~TextureManager(){
	
};


