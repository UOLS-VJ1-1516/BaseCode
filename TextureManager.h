
#pragma once
#include "SDL.h"
#include<map>
class TextureManager
{
private:
	TextureManager();
public:
	static TextureManager* Instance();
	bool load(const char* fileName, const char* id, SDL_Renderer* pRenderer);
	void draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
	std::map<std::string, SDL_Texture*> m_textureMap;
	~TextureManager();
private:
	static TextureManager* s_pInstance;
	SDL_Texture* texture;
};