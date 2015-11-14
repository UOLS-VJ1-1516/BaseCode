#include "MenuState.h"
#include "game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {
	//startButton = new MenuButton((new LoaderParams(150, 50, 44, 40, "coin", 10, 0, 0, 0, 0)), s_menuToPlay);
	startButton = new MenuButton(new LoaderParams(150, 200, 79, 45, "PlayButton", 3, 0, 0, 0, 0), s_menuToPlay);
	exitButton = new MenuButton(new LoaderParams(150, 250, 79, 45, "ExitButton", 3, 0, 0, 0, 0), s_exitFromMenu);

	m_gameObjects.push_back(startButton);
	m_gameObjects.push_back(exitButton);

	TextureManager::Instance()->load("test.bmp", "PlayButton", Game::Instance()->getRender());
	TextureManager::Instance()->load("test.bmp", "ExitButton", Game::Instance()->getRender());

	return true;
}

bool MenuState::onExit() {
	m_gameObjects.clear();

	return true;
}

std::string MenuState::getStateID() const {
	return s_menuID;
}

void MenuState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->clean();
}