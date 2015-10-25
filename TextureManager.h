
#include "game.h"
#include "SDL_image.h"


class TextureManager
{


	SDL_Surface* textureSurface;
	SDL_Texture* texture;
	SDL_Rect  rectanguloFuente;
	SDL_Rect  rectanguloDestino;

private:
	TextureManager();

	~TextureManager();

	/*

public:
	static TextureManager* Instance() {

		if (s_pInstance == 0) {

			s_pInstance = new TextureMananger();
		}
		return s_pInsntance;
	}
	
	~TextureManager();

	bool load(char* fileName, char* id, SDL_Renderer*pRenderer);
	void drawFrame(char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer);

	*/
};


