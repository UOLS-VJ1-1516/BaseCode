#pragma once
#include "game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "player.h"
#include "Enemy.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "MenuState.h"
#include "SoundManager.h"


Game* Game::s_pInstance = 0;

Game::Game()
{
	m_gameStateMachine = new GameStateMachine();
}

Game::~Game()
{}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
				
		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}		

		screenWidth = width;
		screenHeigth = height;

		TheGameObjectFactory->Register("Player", &Player::Create);
		TheGameObjectFactory->Register("Enemy", &Enemy::Create);
		TheGameObjectFactory->Register("MenuButton", &MenuButton::Create);

		SoundManager::Instance()->loadMusic("music.wav", "musicGame");
		SoundManager::Instance()->loadSound("jump.wav", "soundJump");


		m_gameStateMachine->pushState(new MenuState());
		return true;
	}
	return false;

}

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 130, 200, 250, 255);
	SDL_RenderClear(m_pRenderer);

	m_gameStateMachine->render();

	SDL_RenderPresent(m_pRenderer);
}


void Game::update()
{	
	m_gameStateMachine->update();

}

void Game::handleEvents()
{
	InputHandler::Instance()->update();

}

void Game::clean()
{
	quit = 1;
	SDL_RenderClear(m_pRenderer);
	SDL_Quit();
}

bool Game::isRunning()
{
	if (quit != 0) {
		return false;
	}
	return true;
}

SDL_Renderer* Game::getRender() {
	return m_pRenderer;
};

GameStateMachine* Game::getGameStateMachine() {
	return m_gameStateMachine;
}

int Game::getGameWidth() {
	return screenWidth;
}

int Game::getGameHeight() {
	return screenHeigth;
};