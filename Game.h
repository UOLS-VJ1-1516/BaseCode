#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "vector"
#include "Player.h"
#include "Zep.h"
#include "Gordo.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MenuState.h"
#include "PauseState.h"


class Game
{
private:
	Game();
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface * img;
	static Game* s_pInstance;
	LoaderParams* load;
	Player* player;
	LoaderParams* load2;
	Zep* enemy1;
	LoaderParams* load3;
	Gordo* enemy2;
	int spriteNum;
	GameStateMachine *m_pGameStateMachine;
	PlayState* playState;
	MenuState * menuState;
	PauseState * pauseState;



	bool running = true;
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents(SDL_Event event);
	void clean();
	void quit() {running == false; }
	bool isRunning();
	SDL_Renderer* getRender();
	int getTicks();
	std::vector<GameObject*> m_gameObjects;
	GameStateMachine * getGameStateMachine();
	TextureManager* tx;
	InputHandler* th;
};
