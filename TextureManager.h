
#pragma once
#include "SDL.h"
#include<map>

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
class TextureManager
{
private:
	TextureManager();
public:
	static TextureManager* Instance();
	bool load(const char* fileName, const char* id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void clearFromTextureMap(std::string id);
	void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer);
	std::map<std::string, SDL_Texture*> m_textureMap;
	~TextureManager();
private:
	static TextureManager* s_pInstance;
};
#endif TEXTUREMANAGER_H