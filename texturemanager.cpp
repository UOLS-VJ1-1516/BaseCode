#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "texturemanager.h"

TextureManager* TextureManager::s_pInstance = 0;
SDL_Surface* imagen;
SDL_Texture* textura;
SDL_Point* center;


bool TextureManager::load(char* fileName, char* id, SDL_Renderer* g_lRenderer) {



	imagen = IMG_Load(fileName);

	if (imagen == 0) return false;
	SDL_SetColorKey(imagen, 1, SDL_MapRGB(imagen->format, 255, 255, 255));
	SDL_Texture* textura = SDL_CreateTextureFromSurface(g_lRenderer, imagen);
	
	SDL_FreeSurface(imagen);


	//Si todo ha ido bien carga en el mapa
	if (textura != 0) {
		m_textureMap[id] = textura;
		return true;
	}
	else{ //Ha ido mal
		return false;
	}
	
}
void TextureManager::draw(char* id, int x, int y, int width, int height, SDL_Renderer* g_lRenderer, SDL_RendererFlip flip) {
	//�flip ha de ser  SDL_FLIP_NONE
	
	SDL_Rect src;
	SDL_Rect dest;

	src.x = x;
	src.y = y;
	src.w = width;   
	src.h = height;
	dest.w = width;
	dest.h = height;
	dest.x = x+width;
	dest.y = y+height;

	//SDL_RenderCopyEx(g_lRenderer, m_textureMap[id],&src, &dest, 0, center, flip);

}

void TextureManager::drawFrame(char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_lRenderer, SDL_RendererFlip flip) {
	SDL_Rect src;
	SDL_Rect dest;

	//src-->origen, lo que cojo de la imagen
	src.x = currentFrame*width;
	src.y = 0;
	src.w = width;
	src.h = height;
	//Donde y cuanto acabo pintando de la imagen
	dest.x = 600;  //En este caso en el centro de la pantalla
	dest.y = 300;  //currentframe*100  si quiero que se mueva
	dest.w = width;
	dest.h = height;
	

	SDL_RenderCopyEx(g_lRenderer, m_textureMap[id],
		&src, &dest, 0, 0, flip);
}