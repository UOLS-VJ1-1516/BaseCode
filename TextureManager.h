#pragma once
#include <SDL.h>
#include <map>

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
	void draw(std::string textureID, int x, int y, int width, int height, SDL_Renderer* g_pRenderer, SDL_RendererFlip flip);
	void drawFrame(std::string textureID, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_pRenderer,
		SDL_RendererFlip flip);

private:
	static TextureManager* s_pInstance;
	std::map<std::string, SDL_Texture* > m_textureMap;
};

