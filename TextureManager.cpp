#include "TextureManager.h"
#include "Game.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};

bool TextureManager::load(const char* fileName, const char* id) {
	SDL_Surface * surface = SDL_LoadBMP(fileName);
	SDL_SetColorKey(surface, 1, SDL_MapRGB(surface->format, 255, 0, 255));
	SDL_texture = SDL_CreateTextureFromSurface(Game::Instance()->getRender(), surface);
	MAP_textureMap[*id] = SDL_texture;
	SDL_FreeSurface(surface);
	return true;
};

void TextureManager::draw(const char* id, int x, int y, int width, int height, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::srcrect.w = MAP_textureSizes[*id][0];
	TextureManager::srcrect.h = MAP_textureSizes[*id][1];
	TextureManager::srcrect.w = width;
	TextureManager::srcrect.h = height;
	TextureManager::dstrect.x = x;
	TextureManager::dstrect.y = y;
	TextureManager::dstrect.w = width;
	TextureManager::dstrect.h = height;
	SDL_RenderCopyEx(pRender, MAP_textureMap[*id], &srcrect, &dstrect, currentFrame, NULL, flip);
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::srcrect.x = currentFrame*MAP_textureSizes[*id][0];
	TextureManager::srcrect.y = currentRow*MAP_textureSizes[*id][1];
	TextureManager::srcrect.w = MAP_textureSizes[*id][0];
	TextureManager::srcrect.h = MAP_textureSizes[*id][1];
	TextureManager::dstrect.x = x;
	TextureManager::dstrect.y = y;
	TextureManager::dstrect.w = width;
	TextureManager::dstrect.h = height;
	SDL_RenderCopyEx(pRender, MAP_textureMap[*id], &srcrect, &dstrect, 0, 0, flip);
};

void TextureManager::setSizeFrames(const char* id, int w, int h) {
	MAP_textureSizes[*id][0] = w;
	MAP_textureSizes[*id][1] = h;
}

TextureManager::~TextureManager(){
	SDL_surface = NULL;
	SDL_texture = NULL;
	MAP_textureMap.clear();
};

void TextureManager::clean(const char* id) {
	SDL_surface = NULL;
	SDL_texture = NULL;
	MAP_textureMap.erase(*id);
};



