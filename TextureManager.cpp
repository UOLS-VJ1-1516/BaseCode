#include "TextureManager.h"


TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager()
{
};

bool TextureManager::load(const char* filename, const char * clave, SDL_Renderer * imgRender) {

	SDL_Surface *image = SDL_LoadBMP(filename);
	if (!image)	return 1;
	mapaTexture[*clave] = SDL_CreateTextureFromSurface(imgRender, image);
	SDL_FreeSurface(image);
	return 0;

};

void TextureManager::draw(const char*  clave, int x, int y, int width, int height, SDL_Renderer* imgRender, SDL_RendererFlip flip) {
	SDL_RenderClear(imgRender);

	SDL_Rect inTexture, outTexture;

	inTexture.x = 0;
	inTexture.y = 0;
	inTexture.w = width;
	inTexture.h = height;

	outTexture.x = x;
	outTexture.y = y;
	outTexture.w = width;
	outTexture.h = height;
	SDL_RenderCopyEx(imgRender, mapaTexture[*clave], &inTexture, &outTexture, 0, 0, flip);
};

void TextureManager::drawFrame(const char*  clave, int x, int y, int width, int height, int currentFrame, SDL_Renderer* imgRender, SDL_RendererFlip flip) {

	SDL_Rect inTexture, outTexture;

	inTexture.x = currentFrame * width;
	inTexture.y = 0;
	inTexture.w = width;
	inTexture.h = height;


	outTexture.x = x;
	outTexture.y = y;
	outTexture.w = width;
	outTexture.h = height;

	SDL_RenderCopyEx(imgRender, mapaTexture[*clave], &inTexture, &outTexture, 0, 0, flip);
};