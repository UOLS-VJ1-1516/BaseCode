#include "PauseState.h"
#include "game.h"
#include "SoundManager.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->setIsRunning(false);
		SoundManager::Instance()->stopMusic();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter() {
	StateParser::parseState("assets/xml/objects.xml", s_pauseID, &m_gameObjects, &m_texturesIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_resumePlay);
	m_callbacks.push_back(s_pauseToMain);
	setCallbacks(m_callbacks);

	return true;
}

bool PauseState::onExit() {
	for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	for (unsigned int i = 0; i < m_texturesIDList.size(); i++) {
		TextureManager::Instance()->clearFromTextureMap(m_texturesIDList[i]);
	}
	m_texturesIDList.clear();

	return true;
}

std::string PauseState::getStateID() const {
	return s_pauseID;
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void PauseState::s_pauseToMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
	SoundManager::Instance()->stopMusic();
}

void PauseState::s_resumePlay() {
	Game::Instance()->getGameStateMachine()->popState();
}