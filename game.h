#pragma once
#ifndef GAME_H
#define GAME_H
#include <vector>
#include <SDL.h>
#include "SDL_image.h"
#include "time.h"
#include <iostream>
#include <cstdlib>
#include "InputHandler.h"
#include "TextureManager.h"
#include "LoadPar.h"
#include <ctime>
#include "SDL_image.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MenuState.h"
#include "Player.h"
#include "Enemy.h"
#include "Fons.h"





class Game {

private:
	
	Game();
	
	int m_Ancho;
	int m_Alto;
	
	SDL_Window* g_lWindow;
	SDL_Renderer* g_lRenderer;
	SDL_Renderer* g_aRenderer;
	std::vector <GameObject* > m_gameObjects;
	bool running;
	static Game *s_pInstance;
	GameStateMachine * state;
	PlayState * play;
	MenuState * menu;

	//GameStateMachine *m_pGameStateMachine;
	//  bool m_bHasPendingState;
    //GameState *m_pPendingState;

public:
	
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
		}
		return s_pInstance;

	}
	~Game();
	
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	GameStateMachine * getGameStateMachine();
	bool isRunning() {
		return running;
	}
	void quit() {
		running = false; 
		SDL_Quit();
	}

	SDL_Renderer* GetRenderer() const {
		return g_aRenderer;
	}
	int getAncho() const { return m_Ancho; }
	int getAlto() const { return m_Alto; }
	int m_currentFrame;

	// void requestChangeState(GameState *pState);
};
#endif GAME_H


