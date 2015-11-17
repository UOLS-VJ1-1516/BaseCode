#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "InputHandler.h"
#include "GameObject.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	std::cout << "Enter PlayState \n";
	if(!TextureManager::Instance()->load("61933.bmp", "player", Game::Instance()->getRenderer()))
	{
		return false;
	}

	if(!TextureManager::Instance()->load("mantis.bmp", "mantis", Game::Instance()->getRenderer()))
	{
		return false;
	}

	if(!TextureManager::Instance()->load("bat.bmp", "bat", Game::Instance()->getRenderer()))
	{
		return false;
	}
	player = new Player();
	enemy = new Enemy();
	enemy2 = new Enemy();
	player->load(new LoaderParams(300, 220, 73, 58, 8, "player"));
	m_gameObjects.push_back(player);

	enemy->load(new LoaderParams(200, 400, 72, 34, 6, "bat"));
	m_gameObjects.push_back(enemy);

	enemy2->load(new LoaderParams(400, 300, 72, 64, 10, "mantis"));
	m_gameObjects.push_back(enemy2);
	std::cout << "really entering MenuState???\n";
	return true;
}
bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	return true;
}