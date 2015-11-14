#include "PauseState.h"
#include "game.h"

const std::string PauseState::s_pauseID = "PAUSE";

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
	//startButton = new MenuButton((new LoaderParams(150, 50, 44, 40, "coin", 10, 0, 0, 0, 0)), s_menuToPlay);
	resumeButton = new MenuButton(new LoaderParams(150, 200, 79, 45, "ResumeButton", 3, 0, 0, 0, 0), s_resumePlay);
	mainMenuButton = new MenuButton(new LoaderParams(150, 250, 79, 45, "MainMenuButton", 3, 0, 0, 0, 0), s_pauseToMain);

	m_gameObjects.push_back(resumeButton);
	m_gameObjects.push_back(mainMenuButton);

	TextureManager::Instance()->load("test.bmp", "ResumeButton", Game::Instance()->getRender());
	TextureManager::Instance()->load("test.bmp", "MainMenuButton", Game::Instance()->getRender());

	return true;
}

bool PauseState::onExit() {
	m_gameObjects.clear();

	return true;
}

std::string PauseState::getStateID() const {
	return s_pauseID;
}

void PauseState::s_pauseToMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay() {
	Game::Instance()->getGameStateMachine()->popState();
}