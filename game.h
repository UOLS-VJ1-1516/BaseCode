#pragma once
#ifndef GAME_H
#define GAME_H
#include <vector>
#include <SDL.h>
#include "SDL_image.h"
#include "time.h"
#include "PlayState.h"
#include "InputHandler.h"
#include <iostream>
#include "GameStateMachine.h"
#include "texturemanager.h"
#include "MenuState.h"
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Fons.h"





class Game {

private:
	SDL_Window* g_lWindow;
	SDL_Renderer* g_lRenderer;
	std::vector <GameObject* > m_gameObjects;
	bool running;
	



public:
	
	Game();
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
		}
		return s_pInstance;

	}
	~Game();
	static Game* s_pInstance;
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	
	bool isRunning();
	void quit() { running = false; }
	SDL_Renderer* GetRenderer() const {
		return g_lRenderer;
	}
	int GetAncho(){ return ancho; }
	int GetAlto(){ return alto; }
	int Game::getTicks() {
		return (int)(SDL_GetTicks());
	}
	GameStateMachine * Game::getGameStateMachine() {
		return m_pGameStateMachine;
	}
	int ancho;
	int alto;
	TextureManager* textmanager;
	InputHandler* inputhan;
	SDL_Rect dst;
	SDL_Rect org;
	GameStateMachine *m_pGameStateMachine;
	PlayState* playState;
	MenuState * menuState;
	

};
#endif GAME_H


