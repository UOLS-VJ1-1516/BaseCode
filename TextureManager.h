#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <iostream>

class TextureManager
{
private:
	TextureManager();
	std::map<std::string, SDL_Texture *> textures;
	static TextureManager * instance;
public:
	static TextureManager * getInstance()
	{
		if (instance == NULL)
		{
			instance = new TextureManager();
		}
		return instance;
	}
	void clean();
	bool load(std::string file, std::string id, SDL_Renderer * renderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void remove(std::string textureID);
	~TextureManager();
};
