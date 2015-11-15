#include "PlayState.h"
#include "PauseState.h"
#include <iostream>
#include "stdio.h"
const std::string PlayState::s_playID = "PLAY";

bool PlayState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/sonic.bmp", "player", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/enemy.bmp", "enemy", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/enemy.bmp", "enemy1", Game::Instance()->getRenderer()))
	{
		return false;
	}

	player = new Player();
	player->load(new LoaderParams(500, 200, 103, 120, "player", "assets/sonic.bmp", 10, 0));
	enemy1 = new Enemy();
	enemy1->load(new LoaderParams(800, 400, 110, 100, "enemy", "assets/enemy.bmp", 4, 0));
	enemy2 = new Enemy();
	enemy2->load(new LoaderParams(100, 100, 110, 100, "enemy1", "assets/enemy.bmp", 4, 0));
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(enemy2);
	std::cout << "entering PlayState\n";
	return true;
}

void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "exiting PlayState\n";
	return true;
}