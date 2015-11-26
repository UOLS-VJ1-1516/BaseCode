#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	player->update();
	zep->update();
	gordo->update();

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
	zep = new Zep();
	gordo = new Gordo();

	TextureManager::Instance()->load("Kirby.bmp", "player", Game::Instance()->getRender());
	TextureManager::Instance()->load("ZepS.bmp", "zep", Game::Instance()->getRender());
	TextureManager::Instance()->load("GordoS.bmp", "gordo", Game::Instance()->getRender());

	load = new LoaderParams(100, 100, 35, 32, "player", 10);
	load2 = new LoaderParams(200, 200, 89, 78, "zep", 4);
	load3 = new LoaderParams(400, 300, 50, 70, "gordo", 4);

	player->load(load);
	m_gObjects.push_back(player);

	zep->load(load2);
	m_gObjects.push_back(zep);

	gordo->load(load3);
	m_gObjects.push_back(gordo);



	return true;
}


bool PlayState::onExit() {
	m_gObjects.clear();
	return true;
}