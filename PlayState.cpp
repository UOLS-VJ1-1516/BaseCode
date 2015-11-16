#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
//#include "PauseState.h"
#include "InputHandler.h"
#include "GameObject.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	/*if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}*/

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
	GameObject *player;
	GameObject *enemy;
	GameObject *enemy2;

	const LoaderParams* playerLoader;
	const LoaderParams* enemyLoader;
	const LoaderParams* enemy2Loader;

	player = new Player();
	enemy = new Enemy();
	enemy2 = new Enemy();

	playerLoader = new LoaderParams(300, 220, 73, 58, 8, "player");
	enemyLoader = new LoaderParams(200, 400, 72, 34, 6, "bat");
	enemy2Loader = new LoaderParams(400, 300, 72, 64, 10, "mantis");

	TextureManager::Instance()->load("61933.bmp", "player", Game::Instance()->getRenderer());

	TextureManager::Instance()->load("mantis.bmp", "mantis", Game::Instance()->getRenderer());

	TextureManager::Instance()->load("bat.bmp", "bat", Game::Instance()->getRenderer());

	player->load(playerLoader);
	m_gameObjects.push_back(player);

	enemy->load(enemyLoader);
	m_gameObjects.push_back(enemy);

	enemy2->load(enemy2Loader);
	m_gameObjects.push_back(enemy2);

	//	GameObject* player = new Player(new LoaderParams(500, 100, 115, 65, "helicopter"));
	//	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 115, 65, "helicopter"));
	//	m_gameObjects.push_back(player);
	//	m_gameObjects.push_back(enemy);

	return true;
}
bool PlayState::onExit()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	return true;
}