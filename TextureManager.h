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
	//bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture*> m_textureMap;
private:
	static TextureManager* s_pInstance;
	//...
};
