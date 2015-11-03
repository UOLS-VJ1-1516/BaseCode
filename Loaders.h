#pragma once
#include <map>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
private:
	TextureManager();
	std::map<const char*, SDL_Texture *> textures;
	static TextureManager * instancia;
	const char * ASSETS_FOLDER = "assets/";
	const char * IMG_FOLDER = "img/";
public:	
	static TextureManager * GetInstance()
	{
		if (instancia == NULL)
		{
			instancia = new TextureManager();
		}
		return instancia;
	}
	
	bool Load(const char* filename, const char* id);
	std::map<const char *, SDL_Texture *> GetArray() {
		return textures;
	};
	~TextureManager();
};

