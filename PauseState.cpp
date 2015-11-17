#include "PauseState.h"
#include "Game.h"


void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter() {

	GameObject *menuButton = new MenuButton(new LoaderParams(200, 200, 250, 69, "playbtn.bmp", 3), s_menuTOPlay);
	if (menuButton == NULL) {
		return false;
	}
	TextureManager::Instance()->load("playbtn.bmp", "playbtn.bmp", Game::Instance()->getRender());
	m_gameObjects.push_back(menuButton);
	GameObject* menuButton2 = new MenuButton(new LoaderParams(200, 300, 250, 69, "exitbtn.bmp", 3), s_menuTOMain);
	if (menuButton2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton2);
	TextureManager::Instance()->load("exitbtn.bmp", "exitbtn.bmp", Game::Instance()->getRender());

	std::cout << "Entrada al menuState\n";
	return true;

	
}
bool PauseState::onExit() {
	m_gameObjects.clear();
	
	return true;
}

const std::string PauseState::s_pauseID = "PAUSE";

std::string PauseState::getStateID() const {
	return PauseState::s_pauseID;
}

void PauseState::s_menuTOMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::s_menuTOPlay() {
	Game::Instance()->getGameStateMachine()->popState();
}

