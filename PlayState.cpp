#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"

void PlayState::update() {
	player->update();
	enemy1->update();
	borot->update();

	for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->update();
	}
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {

		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}
}

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	player = new Player();
	enemy1 = new Enemy();
	borot = new Enemy();

	TextureManager::Instance()->load("Player.bmp", "player", Game::Instance()->getRender());
	TextureManager::Instance()->load("Enemy1.bmp", "enemy1", Game::Instance()->getRender());
	TextureManager::Instance()->load("Calvo.bmp", "borot", Game::Instance()->getRender());

	load = new LoaderParams(100, 200, 50, 100, "player", 4);
	load2 = new LoaderParams(200, 70, 70, 100, "enemy1", 4);
	load3 = new LoaderParams(450, 300, 60, 100, "borot", 4);

	player->load(load);
	m_gObjects.push_back(player);

	enemy1->load(load2);
	m_gObjects.push_back(enemy1);

	borot->load(load3);
	m_gObjects.push_back(borot);

	return true;
}

const std::string PlayState::s_playID = "PLAY";

bool PlayState::onExit() {
	m_gObjects.clear();
	return true;
}

