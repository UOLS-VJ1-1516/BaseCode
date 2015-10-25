#include "Loaders.h"

TextureManager * TextureManager::instancia = 0;
void TextureManager::Draw(const char * id, int x, int y, int width, int height, SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = width;
	rect.h = height;

	SDL_Rect draw;
	draw.x = x;
	draw.y = y;
	draw.w = width * 2;
	draw.h = height * 2;

	SDL_Texture * textura = textures[id];
	SDL_RenderCopyEx(renderer, textura, &rect, &draw, 0, NULL, flip);
}

void TextureManager::Draw(Player * player, SDL_Renderer * renderer)
{
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if (player->IsFlipped())
		flip = SDL_FLIP_HORIZONTAL;
	Draw(player->GetId(), player->GetPos('X'), player->GetPos('Y'), player->GetSize('w'), player->GetSize('h'), renderer, flip);
}

void TextureManager::DrawFrame(Player * player, SDL_Renderer * renderer)
{
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if (player->IsFlipped())
		flip = SDL_FLIP_HORIZONTAL;
	DrawFrame(player->GetId(), player->GetPos('X'), player->GetPos('Y'), player->GetSize('w'), player->GetSize('h'), player->GetRow(), player->GetFrame(), renderer, flip);
}

void TextureManager::DrawFrame(const char * id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect rect;
	rect.x = width * currentFrame;
	rect.y = height * currentRow;
	rect.w = width;
	rect.h = height;

	SDL_Rect draw;
	draw.x = x;
	draw.y = y;
	draw.w = width;
	draw.h = height;

	SDL_Texture * textura = textures[id];
	SDL_RenderCopyEx(renderer, textura, &rect, &draw, 0, NULL, flip);
}

bool TextureManager::Load(const char * filename, const char * id, SDL_Renderer * renderer)
{
	SDL_Surface * surface = IMG_Load(filename);
	SDL_Texture * textura = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	textures[id] = textura;
	if (textura == NULL)
		return false;
	return true;
}

TextureManager::TextureManager()
{
	instancia = 0;
}

TextureManager::~TextureManager()
{
	instancia = NULL;
	textures.~map();
}

