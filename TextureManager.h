#pragma once

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL.h"
#include "map"

class TextureManager {
	private:
		TextureManager();

	public:
		static TextureManager* Instance() {
			if (s_pInstance == 0) {
				s_pInstance = new TextureManager();
			}
			return s_pInstance;
		}
		~TextureManager();

		bool load(const char* fileName, const char* key, SDL_Renderer* m_pRenderer);
		void draw(const char* key, int x, int y, int width, int height, SDL_Renderer* m_pRenderer, SDL_RendererFlip m_pFlip);
		void drawFrame(const char* key, int x, int y, int width, int height, int currentFrame, int currentRow, SDL_Renderer* m_pRenderer, SDL_RendererFlip m_pFlip);

	private:
		static TextureManager* s_pInstance;
		std::map<char, SDL_Texture* > textureMap;
};

#endif
