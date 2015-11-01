#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>

class Element {


public:
		Element* Instance(){}
		~Element();

		bool load(const char* nomarxiu, const char* id, SDL_Renderer* g_lRenderer);
		void draw(const char* id, int x, int y, int width, int height, SDL_Renderer* g_lRenderer, SDL_RendererFlip SDL_FLIP_NONE);
private:
	SDL_Rect dst;
	SDL_Rect org;
	int width;
	int height;

		


};