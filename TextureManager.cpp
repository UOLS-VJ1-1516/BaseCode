#include "TextureManager.h"
#include "SDL_image.h"

	TextureManager::TextureManager(){
	}
	TextureManager* TextureManager::Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	TextureManager::~TextureManager() {}
	bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer* pRenderer) {
		SDL_Surface* surface;
		surface = IMG_Load(fileName);
		texture = SDL_CreateTextureFromSurface(pRenderer, surface);
		SDL_FreeSurface(surface);
		if (texture != 0)
		{
			m_textureMap[id] = texture;
			return true;
		}
		return false;
	}
	void TextureManager::draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip) {
		SDL_Rect srcRect;
		SDL_Rect destRect;
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;
		SDL_RenderCopyEx(pRender, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
	}
	void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
		SDL_Rect srcRect;
		SDL_Rect destRect;
		srcRect.x = width * currentFrame;
		srcRect.y = height * (currentRow - 1);
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;
		SDL_RenderCopyEx(pRender, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
	}