#pragma once
#include "PauseState.h"
#include "game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "StateParser.h"

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

	if (!TextureManager::Instance()->load("resume.bmp", "resume", Game::Instance()->getRender())) {
		return false;
	}
	if (!TextureManager::Instance()->load("mainmenu.bmp", "mainmenu", Game::Instance()->getRender())) {
		return false;
	}

	StateParser stateParser;
	stateParser.parseState("XMLFile.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	
	m_callbacks.push_back(0); 
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_menuToMain);
	setCallbacks(m_callbacks);

	return true;
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	for (unsigned int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearTexture(m_textureIDList[i]);
	}
	m_textureIDList.clear();

	return true;
}

const std::string PauseState::s_pauseID = "PAUSE";

std::string PauseState::getStateID() const {

	return PauseState::s_pauseID;
}

void PauseState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->popState();
}

void PauseState::s_menuToMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
			if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
			{
				MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
				pButton->setCallbacks(callbacks[pButton->getCallbackID()]);
			}
	}
}
