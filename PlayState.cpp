#include "PlayState.h"
#include "Game.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "TextureManager.h"


void PlayState::update() {
	if (InputHandler::Instance()->isKeyDown(SDLK_ESCAPE)) Game::Instance()->getStateMachine()->pushState(new MenuStateOnPause());
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool PlayState::onEnter() {
	GameObject *enemy = new Enemy();
	enemy->load(new LoaderParams(40, 30, "enemy2", 120, 2, 0, *(new Vector2D(0, 50)), *(new Vector2D(2, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(enemy);
	TextureManager::Instance()->load("enemy.bmp", "enemy", Game::Instance()->getRenderer());

	GameObject *enemy2 = new Enemy();
	enemy2->load(new LoaderParams(40, 30, "enemy2", 80, 2, 0, *(new Vector2D(100, 100)), *(new Vector2D(15, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(enemy2);
	TextureManager::Instance()->load("enemy.bmp", "enemy2", Game::Instance()->getRenderer());

	GameObject *enemy3 = new Enemy();
	enemy3->load(new LoaderParams(40, 30, "enemy3", 120, 2, 0, *(new Vector2D(0, 150)), *(new Vector2D(1, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(enemy3);
	TextureManager::Instance()->load("enemy.bmp", "enemy3", Game::Instance()->getRenderer());

	GameObject *enemy4 = new Enemy();
	enemy4->load(new LoaderParams(40, 30, "enemy4", 80, 2, 0, *(new Vector2D(50, 250)), *(new Vector2D(5, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(enemy4);
	TextureManager::Instance()->load("enemy.bmp", "enemy4", Game::Instance()->getRenderer());

	GameObject *player = new Player();
	player->load(new LoaderParams(13, 30, "mario", 0, 2, 0, *(new Vector2D(300, 200)), *(new Vector2D(0, 0)), *(new Vector2D(15, 0)), *(new Vector2D(1, 0)), *(new Vector2D(1, 0))));

	m_gameObjects.push_back(player);
	TextureManager::Instance()->load("mario.bmp", "mario", Game::Instance()->getRenderer());
		

	return true;
};


bool PlayState::onExit() {
	m_gameObjects.clear();
	return true;
};

const std::string PlayState::s_playID = "Play";

std::string PlayState::getStateID() const {
	return PlayState::s_playID;
};