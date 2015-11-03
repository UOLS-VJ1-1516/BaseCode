#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager(){};
TextureManager::~TextureManager(){};

bool TextureManager::load(char* fileName, const char* id, SDL_Renderer* pRenderer) {
	texture = IMG_LoadTexture(pRenderer, fileName);
	return true;
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	SrcR.x = currentFrame * m_textureSizes[*id][0];
	SrcR.y = currentRow * m_textureSizes[*id][1];

	SrcR.w = m_textureSizes[*id][0];
	SrcR.h = m_textureSizes[*id][1];

	DestR.x = m_texturePositions[*id][0];
	DestR.y = m_texturePositions[*id][1];

	DestR.w = m_textureSizes[*id][0];
	DestR.h = m_textureSizes[*id][1];

	SDL_RenderCopy(pRender, m_textureMap[*id], &SrcR, &DestR);
};

void TextureManager::setFrame(const char* id, int x, int y, int w, int h) {
	m_textureMap[*id] = texture;
	m_texturePositions[*id][0] = x;
	m_texturePositions[*id][1] = y;
	m_textureSizes[*id][0] = w;
	m_textureSizes[*id][1] = h;
}