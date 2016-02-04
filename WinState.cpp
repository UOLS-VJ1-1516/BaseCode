#include "WinState.h"
#include "game.h"
#include "SoundManager.h"

const std::string WinState::s_winID = "WIN";

void WinState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void WinState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool WinState::onEnter() {
	StateParser::parseState("assets/xml/objects.xml", s_winID, &m_gameObjects, &m_texturesIDList);
	SoundManager::Instance()->stopMusic();
	SoundManager::Instance()->playMusic("win", 0);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_winToMain);
	setCallbacks(m_callbacks);

	return true;
}

bool WinState::onExit() {
	for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	for (unsigned int i = 0; i < m_texturesIDList.size(); i++) {
		TextureManager::Instance()->clearFromTextureMap(m_texturesIDList[i]);
	}
	m_texturesIDList.clear();

	SoundManager::Instance()->stopMusic();

	return true;
}

std::string WinState::getStateID() const {
	return s_winID;
}

void WinState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void WinState::s_winToMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
	SoundManager::Instance()->stopMusic();
}
