#include "texturemanager.h"

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

bool TextureManager::load(char* fileName, char* id, SDL_Renderer* g_Render) {
	
	SDL_Surface* fichero;
	SDL_Texture* textura;

	//cargamos imagen
	fichero = IMG_Load(fileName);
	if (fichero == 0) {
		return false; //comprobacion fichero
	}

	//para volver transparente el fondo de la imagen, colocamos el color rgb del fondo (109, 73, 137)
	SDL_SetColorKey(fichero, 1, SDL_MapRGB(fichero->format, 109, 73, 137));

	//crear la textura
	textura = SDL_CreateTextureFromSurface(g_Render, fichero);

	SDL_FreeSurface(fichero);

	m_textureMap[id] = textura;

	return true;
};

void TextureManager::draw(char* id, int x, int y, int width, int height, SDL_Renderer* g_Render, SDL_RendererFlip flip) {

	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = x;
	srcRect.y = y;
	srcRect.w = width;
	srcRect.h = height;
	destRect.x = x;
	destRect.y = y;
	destRect.w = width;
	destRect.h = height;
	

	SDL_RenderCopyEx(g_Render, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_Render, SDL_RendererFlip flip) {
	
	SDL_Rect srcRect;
	SDL_Rect destRect;

	// origen
	srcRect.x = currentFrame*width;
	srcRect.y = currentRow*height;
	srcRect.w = width;
	srcRect.h = height;
	
	//destino
	destRect.x = x;
	destRect.y = y;
	destRect.w = width;
	destRect.h = height;

	SDL_RenderCopyEx(g_Render, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
};

void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
};
void TextureManager::clear(std::string id) {
	m_textureMap.erase(id);
}