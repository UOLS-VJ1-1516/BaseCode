#include "PauseState.h"


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

	if (!TextureManager::Instance()->load("play.bmp", "playPausa", Game::Instance()->getRender()))
	{
		printf("false");
		return false;
	}
	if (!TextureManager::Instance()->load("Exit.bmp", "exitPausa", Game::Instance()->getRender()))
	{
		return false;
	}

	GameObject* menuButton = new MenuButton(new LoaderParams(200, 200, 201, 72, "playPausa", 3), s_menuTOPlay);
	if (menuButton == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton);
	GameObject* menuButton2 = new MenuButton(new LoaderParams(200, 200, 201, 72, "exitPausa", 3), s_menuTOMain);
	if (menuButton2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton2);

	return true;

	
}
bool PauseState::onExit() {
	m_gameObjects.clear();
	mb->clean();
	mb2->clean();
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

