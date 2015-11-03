#include "TextureManager.h"
#include "game.h"
#include "stdio.h"
#include "SDL_image.h"

// Instancia de TextureManager
TextureManager* TextureManager::s_pInstance = 0;

// Constructor y destructor
TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

// Carrgar Texturas
bool TextureManager::load(char* fileName, const char* id, SDL_Renderer* pRenderer) {
	texture = IMG_LoadTexture(pRenderer, fileName);
	return true;
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	// Posición (x,y) del rectangulo rojo indicando posicion del spritesheet
	SrcR.x = currentFrame * m_textureSizes[*id][0];
	SrcR.y = currentRow * m_textureSizes[*id][1];

	// Tamaño del trozo de spritesheet que coje
	SrcR.w = m_textureSizes[*id][0];
	SrcR.h = m_textureSizes[*id][1];

	// Posicion donde colocar el rectangulo rojo
	DestR.x = m_texturePositions[*id][0];
	DestR.y = m_texturePositions[*id][1];

	// Tamaño del rectangulo rojo
	DestR.w = m_textureSizes[*id][0];
	DestR.h = m_textureSizes[*id][1];

	SDL_RenderCopy(pRender, m_textureMap[*id], &SrcR, &DestR);
};

//Funcion para crear el mapa de texturas
void TextureManager::setFrame(const char* id, int x, int y, int w, int h) {
	m_textureMap[*id] = texture;
	m_texturePositions[*id][0] = x;
	m_texturePositions[*id][1] = y;
	m_textureSizes[*id][0] = w;
	m_textureSizes[*id][1] = h;
}