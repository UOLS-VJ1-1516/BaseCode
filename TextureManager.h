#pragma once
#include <SDL.h>
#include <map>
class TextureManager
{
private:
	TextureManager();
public:
	static TextureManager* Instance() {

		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	~TextureManager();

	bool load(const char* fileName, const char* clave, SDL_Renderer* imgRender);
	void draw(const char* clave, int x, int y, int width, int height, SDL_Renderer* imgRender, SDL_RendererFlip flip);
	void drawFrame(const char* clave, int x, int y, int width, int height, int currentFrame, SDL_Renderer* imgRender,
		SDL_RendererFlip flip);

private:
	static TextureManager* s_pInstance;
	std::map<char, SDL_Texture* > mapaTexture;
};
