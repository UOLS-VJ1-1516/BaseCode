#include "TextureManager.h"

TextureManager * TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};

bool TextureManager::load(const char* fileName, std::string textureID, SDL_Renderer* g_pRenderer) {

	SDL_Surface *image = SDL_LoadBMP(fileName);
	if (!image)	return 1;

	m_textureMap[textureID] = SDL_CreateTextureFromSurface(g_pRenderer, image);
	SDL_FreeSurface(image);
	return 0;

};

void TextureManager::draw(std::string textureID, int x, int y, int width, int height, SDL_Renderer* g_pRenderer, SDL_RendererFlip flip) {
	SDL_RenderClear(g_pRenderer);

	SDL_Rect source, destination;

	source.x = 0;
	source.y = 0;
	source.w = width;
	source.h = height;

	destination.x = x;
	destination.y = y;
	destination.w = width;
	destination.h = height;
	SDL_RenderCopyEx(g_pRenderer, m_textureMap[textureID], &source, &destination, 0, 0, flip);
};

void TextureManager::drawFrame(std::string textureID, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_pRenderer, SDL_RendererFlip flip) {

	SDL_Rect source, destination;
	SDL_RendererFlip rendererFlip;

	// Imágen propiedades internas
	source.x = currentFrame * width;
	source.y = currentRow;
	source.w = width;
	source.h = height;

	// Imagen respecto a la ventana.
	destination.x = x;
	destination.y = y;
	destination.w = width;
	destination.h = height;

	SDL_RenderCopyEx(g_pRenderer, m_textureMap[textureID], &source, &destination, 0, 0, flip);
};




