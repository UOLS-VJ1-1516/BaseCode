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

	bool load(const char* fileName, const char* key, SDL_Renderer* g_pRenderer);
	void draw(const char* key, int x, int y, int width, int height, SDL_Renderer* g_pRenderer, SDL_RendererFlip flip);
	void drawFrame(const char* key, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_pRenderer,
		SDL_RendererFlip flip);

private:
	static TextureManager* s_pInstance;
	std::map<char, SDL_Texture* > m_textureMap;
};