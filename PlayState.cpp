#include "PlayState.h"
#include "Game.h"

void PlayState::update() {
	/*player->update();
	zep->update();
	gordo->update();*/

	for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->update();
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

	load = new LoaderParams(100, 100, 35, 32, "player", 10);
	load2 = new LoaderParams(200, 200, 89, 78, "zep", 4);
	load3 = new LoaderParams(400, 300, 50, 70, "gordo", 4);

	player->load(load);
	m_gObjects.push_back(player);

	zep->load(load2);
	m_gObjects.push_back(zep);

	gordo->load(load3);
	m_gObjects.push_back(gordo);

	TextureManager::Instance()->load("Kirby.bmp", "player", m_pRenderer);
	TextureManager::Instance()->load("ZepS.bmp", "zep", m_pRenderer);
	TextureManager::Instance()->load("GordoS.bmp", "gordo", m_pRenderer);
}

const std::string PlayState::s_playID = "PLAY";
bool PlayState::onExit() {
	m_gObjects.clear();
	return true;
}

std::string PlayState::getStateID() const {
	return PlayState::s_playID;
}