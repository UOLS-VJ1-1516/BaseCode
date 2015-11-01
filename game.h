#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "vector"


class Game
{
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	SDL_Surface* image;
	
	int quit = 0;
	int spriteNum;
	int numRow;

public:
	Game();
	~Game();

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}
	
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	SDL_Renderer* getRender();
	

private:
	static Game* s_pInstance;
	GameObject* go;
	std::map< char, SDL_Texture* > m_textureMap;
	std::vector< GameObject* > m_gameObjects;


};