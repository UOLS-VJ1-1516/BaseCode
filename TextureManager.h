#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "map"

class TextureManager
{
private:
	TextureManager();

public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	~TextureManager();

	bool load(std::string fileName, std::string id,	SDL_Renderer* pRenderer);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer*	pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void TextureManager::clearFromTextureMap(std::string id) { m_textureMap.erase(id); };
private:
	static TextureManager* s_pInstance;
	SDL_Texture* texture;
	SDL_Rect SrcR;
	SDL_Rect DestR;
	std::map<std::string, SDL_Texture*> m_textureMap;
};