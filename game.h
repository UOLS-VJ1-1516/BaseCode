#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "vector"
#include "Player.h"


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
	Player* p1;
	Player* p2;
	Player* p3;
	std::map< char, SDL_Texture* > m_textureMap;
	std::vector< Player* > m_gameObjects;


};