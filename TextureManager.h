/*
#include "SDL.h"
#include "SDL_image.h"


class TextureManager {
	SDL_Texture* texture;
	SDL_Rect SrcR;
	SDL_Rect DestR;


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

		bool load(char* fileName, char* id, SDL_Renderer* pRenderer);
		void drawFrame(char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender);

		private:
			static TextureManager* s_pInstance;
};
*/


