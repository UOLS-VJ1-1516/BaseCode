#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
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
	bool load(std::string file, std::string id, SDL_Renderer* m_pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture*> m_textureMap;
	void TextureManager::clearFromTextureMap(std::string id) { m_textureMap.erase(id); };
private:
	static TextureManager* s_pInstance;
	//...
};
