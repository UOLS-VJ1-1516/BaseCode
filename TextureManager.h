#pragma once
#include "SDL.h"
#include <map>
#include "SDL_image.h"

class TextureManager
{
	SDL_Surface* image;
	SDL_Texture* texture;
	SDL_Rect Src;
	SDL_Rect Dest;


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
		
		bool load(std::string fileName, std::string id, SDL_Renderer* m_pRenderer);
		void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
		void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);


	private:
		static TextureManager* s_pInstance;
		std::map< std::string, SDL_Texture* > m_textureMap;
		
};
