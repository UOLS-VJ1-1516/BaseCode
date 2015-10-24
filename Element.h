#pragma once
#include <SDL.h>
#include <map>

class Element
{

public:
	Element* Instance(){}
	~Element();

	bool load(const char* fileName, const char* key, SDL_Renderer* g_pRenderer);
	void draw(const char* key, int x, int y, int width, int height, SDL_Renderer* g_pRenderer, SDL_RendererFlip flip);
	void drawFrame(const char* key, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_pRenderer,
		SDL_RendererFlip flip);

private:
	int width;
	int height;
	SDL_Rect inObject;
	SDL_Rect outObject;

};
