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

	bool load(char* fileName, const char* id, SDL_Renderer* pRenderer);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void TextureManager::clearFromTextureMap(std::string id) { 
		m_textureMap.erase(id); 
	};
private:
	static TextureManager* s_pInstance;
	SDL_Texture* texture;
	SDL_Rect SrcR;
	SDL_Rect DestR;
	std::map<std::string, SDL_Texture*> m_textureMap;
};