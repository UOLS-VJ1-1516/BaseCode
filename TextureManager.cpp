#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager(){};



bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer* pRenderer) {
	TextureManager::SrcR.x = 0;
	TextureManager::SrcR.y = 0;
	TextureManager::SrcR.w = SHAPE_SIZE;
	TextureManager::SrcR.h = SHAPE_SIZE;

	TextureManager::DestR.x = 640 / 2 - SHAPE_SIZE / 2;
	TextureManager::DestR.y = 580 / 2 - SHAPE_SIZE / 2;
	TextureManager::DestR.w = SHAPE_SIZE;
	TextureManager::DestR.h = SHAPE_SIZE;

	s_surface = SDL_LoadBMP(fileName);
	s_texture = SDL_CreateTextureFromSurface(pRenderer, s_surface);
	m_textureMap[*id] = s_texture;
	return true;
};

void TextureManager::draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	SDL_RenderCopy(pRender, s_texture,&SrcR, &DestR);
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {

};

TextureManager::~TextureManager(){
	
};


