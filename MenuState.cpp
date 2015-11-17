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
	startButton = new MenuButton(new LoaderParams(275, 225, 250, 75, "PlayButton", 3, 0, 0, 0, 0), s_menuToPlay);
	exitButton = new MenuButton(new LoaderParams(275, 325, 250, 75, "ExitButton", 3, 0, 0, 0, 0), s_exitFromMenu);

	m_gameObjects.push_back(startButton);
	m_gameObjects.push_back(exitButton);

	TextureManager::Instance()->load("playButton.bmp", "PlayButton", Game::Instance()->getRender());
	TextureManager::Instance()->load("exitButton.bmp", "ExitButton", Game::Instance()->getRender());

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
	Game::Instance()->setIsRunning(false);
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->clean();
}