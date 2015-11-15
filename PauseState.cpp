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
	mb = new MenuButton(new LoaderParams(mig(236, 75)[0], mig(236, 75)[1] - 50, 236, 75, "playButton.bmp", 3, 0, 0, 0, 0), s_menuTOPlay);
	if (mb == NULL) {
		return false;
	}
	m_gameObjects.push_back(mb);
	mb2 = new MenuButton(new LoaderParams(mig(236, 75)[0], mig(236, 75)[1] - 50, 236, 75, "Exit.bmp", 3, 0, 0, 0, 0), s_menuTOMain);
	if (mb2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(mb2);

	
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

std::vector<int>MenuState::mig(int width, int height) {
	m_position = std::vector<int>(2, 0);

	return m_position;
}

