#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->setIsRunning(false);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		player1->incrementAcceleration();
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		player1->decrementAcceleration();
	}

	InputHandler::Instance()->clean();
}

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	player1 = new Player();
	enemy1 = new Enemy();
	stObj1 = new StaticObject();
	paramsPlayer1 = new LoaderParams(0, 400, 100, 101, "Player", 6, 0, 0, 30, 0.1);
	paramsEnemy1 = new LoaderParams(350, 100, 256, 256, "Zombie", 6, 3, 0, 10, 0.1);
	paramsStObj1 = new LoaderParams(150, 50, 44, 40, "coin", 10, 0, 0, 0, 0);

	player1->load(paramsPlayer1);
	enemy1->load(paramsEnemy1);
	stObj1->load(paramsStObj1);

	m_gameObjects.push_back(player1);
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(stObj1);

	//load img in my img list
	TextureManager::Instance()->load("buffon.bmp", "Player", Game::Instance()->getRender());
	TextureManager::Instance()->load("coin.bmp", "coin", Game::Instance()->getRender());
	TextureManager::Instance()->load("zombie1.bmp", "Zombie", Game::Instance()->getRender());

	return true;
}

bool PlayState::onExit() {
	m_gameObjects.clear();

	return true;
}

std::string PlayState::getStateID() const{
	return s_playID;
}