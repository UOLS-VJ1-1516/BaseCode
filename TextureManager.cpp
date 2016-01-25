#include "TextureManager.h"

// Instancia de TextureManager
TextureManager* TextureManager::s_pInstance = 0;

// Constructor y destructor
TextureManager::TextureManager() {};
TextureManager::~TextureManager() {};

// Funcion para cargar la textura
bool TextureManager::load(std::string fileName, std::string	id, SDL_Renderer* pRenderer)
{

	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == 0)
	{
		return false;
	}
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}
//Funcion para mostrar textura por pantalla
void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
//sirve para dibujar los tiles
//(id, margen, spacing, x,y,width, height, currentRoww, currentFrame, SDL_REnderer)
void TextureManager::drawTile(std::string id, int margin, int
	spacing, int x, int y, int width, int height, int currentRow,
	int currentFrame, SDL_Renderer *pRenderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	//calcular su posicion dado cuenta margen y espacio
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}
