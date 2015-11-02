#include "SDL.h"
#include "game.h"
#include "SDL_image.h"
#pragma once
//#include "TextureManager.cpp"


class TextureManager{


	SDL_Surface textureSurface;
	SDL_Texture* texture;
	SDL_Rect  rectanguloFuente;
	SDL_Rect  rectanguloDestino;


private:
      TextureManager();

public:
     static TextureManager* Instance() {

		if (s_pInstance == 0) {
        s_pInstance = new TextureManager();
		}
			return s_pInstance;
	}
	
	~TextureManager();

  bool load(char* fileName, char* id, SDL_Renderer*pRenderer);
    void drawFrame(char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer);
        static TextureManager* s_pInstance;
};


