#include "TextureManager.h"

using namespace std;

TextureManager * TextureManager::instance = 0;

TextureManager::TextureManager(){/*VOID*/};

bool TextureManager::load(const char* file, string id, SDL_Renderer * renderer) {
	SDL_Surface * surface = IMG_Load(file);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

	textures[id] = texture;
	if (texture == NULL) {
		return false;
	}
	return true;
}

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer * renderer, SDL_RendererFlip flip) {
	SDL_Texture * texture = textures[id];
	SDL_Rect rectWorld, rectSprite;
	rectSprite.x = 0;
	rectSprite.y = 0;
	rectSprite.w = width;
	rectSprite.h = height;

	rectWorld.x = x-width/2;
	rectWorld.y = y-height/2;
	rectWorld.w = width;
	rectWorld.h = height;

	SDL_RenderCopyEx(
		renderer,		//render
		texture,		//texture
		&rectSprite,	//sprite
		&rectWorld,		//destiny
		0,				//rotation degrees
		NULL,			//center point
		flip			//SDL_FLIP_NONE/VERTICAL/HORIZONTAL
	);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * renderer, SDL_RendererFlip flip) {
	SDL_Texture * texture = textures[id];
	SDL_Rect rectWorld, rectSprite;
	rectSprite.x = width*currentFrame;
	rectSprite.y = height*currentRow;
	rectSprite.w = width;
	rectSprite.h = height;

	rectWorld.x = x-width/2;
	rectWorld.y = y-height/2;
	rectWorld.w = width;
	rectWorld.h = height;

	SDL_RenderCopyEx(
		renderer,		//render
		texture,		//texture
		&rectSprite,	//sprite
		&rectWorld,		//spriteDestiny
		0,				//rotation degrees
		NULL,			//center point
		flip			//SDL_FLIP_NONE/VERTICAL/HORIZONTAL
	);
}
