#include "TextureManager.h"
#include "game.h"

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager()
{

};

TextureManager::~TextureManager()
{

};

bool TextureManager::load(char* fileName, char* id, SDL_Renderer* m_pRenderer) {
	player = SDL_LoadBMP(fileName);
	SDL_SetColorKey(player, 1, SDL_MapRGB(player->format, 30, 255, 0));
	texture = SDL_CreateTextureFromSurface(m_pRenderer, player);
	m_pTextureMap[*id] = texture;
	return true;
};

void TextureManager::draw(char* id, int x, int y, int width, int height,
	SDL_Renderer*pRender, SDL_RendererFlip flip = SDL_FLIP_NONE) {

	marcI.x = 0;
	marcI.y = 0;
	marcI.w = width;
	marcI.h = height;
	marcF.h = height;
	marcF.w = width;
	marcF.x = 20;
	marcF.y = 50;

	SDL_RenderCopyEx(pRender, m_pTextureMap[*id], &marcI, &marcF, 0, center, flip);

};

void TextureManager::drawFrame(char* id, int x, int y, int width, int height,
	int currentRow, int currentFrame,
	SDL_Renderer* pRender, SDL_RendererFlip flip) {

	marcI.x = currentFrame*45;//alto y anchod de los frames
	marcI.y = height*currentRow;//fila 0
	marcI.w = width;
	marcI.h = height;

	marcF.x = x;
	marcF.y = y;
	marcF.w = width;
	marcF.h = height;

	SDL_RenderCopyEx(pRender, texture, &marcI, &marcF, 0, 0, flip);


};
