/*
#include "TextureManager.h"
#include "game.h"

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager()
{

};

TextureManager::~TextureManager()
{

};

bool TextureManager::load(char* fileName, char* id, SDL_Renderer* pRenderer) {
	texture = IMG_LoadTexture(pRenderer, fileName);
	return true;
};

void TextureManager::drawFrame(char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender) {

	//Posición (x,y) del rectangulo rojo indicando posicion del spritesheet
	SrcR.x = currentFrame * width;
	SrcR.y = currentRow * height;
	//Tamaño del trozo de spritesheet que coje
	SrcR.w = width;
	SrcR.h = height;
	//Posicion donde colocar el rectangulo rojo
	DestR.x = (1600 / 2) - width;
	DestR.y = (900 / 2) - height;
	//Tamaño del rectangulo rojo
	DestR.w = width;
	DestR.h = height;

	SDL_RenderCopy(pRender, texture, &SrcR, &DestR);
};
*/