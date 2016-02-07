#pragma once
#include <SDL.h>
#include <map>
#include "SDL_image.h"

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

	bool load(const char* fileName, std::string textureID, SDL_Renderer* g_pRenderer);
	void draw(std::string textureID, float x, float y, int width, int height, SDL_Renderer* g_pRenderer, SDL_RendererFlip flip);
	void drawFrame(std::string textureID, float x, float y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_pRenderer,
		int flip);
	void drawTile(std::string textureID, int margin, int spacing, int x, int y, int width, int height, int currentRow,
		int currentFrame, SDL_Renderer *pRenderer);
	void TextureManager::clearFromTextureMap(std::string id);
	void setSizeFrames(const char* id, int width, int height);
private:
	static TextureManager* s_pInstance;
	std::map<std::string, SDL_Texture* > m_textureMap;
};