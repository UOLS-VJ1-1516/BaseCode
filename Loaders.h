#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include "Player.h"

class TextureManager
{
private:
	TextureManager();
	std::map<const char*, SDL_Texture *> textures;
	static TextureManager * instancia;
public:	
	static TextureManager * GetInstance()
	{
		if (instancia == NULL)
		{
			instancia = new TextureManager();
		}
		return instancia;
	}
	
	void Draw(const char * id, int x, int y, int width, int height, SDL_Renderer *, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Draw(Player *, SDL_Renderer *);
	void DrawFrame(const char *, int, int, int, int, int currentRow, int currentFrame, SDL_Renderer *, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(Player *, SDL_Renderer *);
	bool Load(const char* filename, const char* id, SDL_Renderer *);
	~TextureManager();
};

