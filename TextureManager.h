#pragma once
#ifndef TEXTUREMANAGER_H
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

	bool load(std::string fileName, std::string id, SDL_Renderer *m_pRenderer);
	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer*pRender, SDL_RendererFlip flip);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRender, SDL_RendererFlip flip);

	void TextureManager::clearFromTextureMap(std::string id) { m_pTextureMap.erase(id); };
	void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer);

private:
	static TextureManager* s_pInstance;
	std::map<std::string, SDL_Texture*>m_pTextureMap;
	std::map<std::string, int[2] > m_textureSizes;
	SDL_Surface * img;
	SDL_Texture*texture;
	SDL_Point*center;
	SDL_Rect inicio;
	SDL_Rect dest;
};

#endif