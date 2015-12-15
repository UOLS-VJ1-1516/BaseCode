#pragma once
#include "MenuState.h"
#include "TextureManager.h"
#include "game.h"
#include "PlayState.h"
#include "StateParser.h"
#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {

	if (!TextureManager::Instance()->load("play.bmp", "play", Game::Instance()->getRender())) {
		return false;
	}
	if (!TextureManager::Instance()->load("exit.bmp", "exit", Game::Instance()->getRender())) {
		return false;
	}

	StateParser stateParser;
	stateParser.parseState("XMLFile.xml", s_menuID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0); //El primero vacío
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);
	
	return true;
}

bool MenuState::onExit() {

	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearTexture(m_textureIDList[i]);
	}

	return true;
}

void MenuState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->clean();
}

void MenuState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallbacks(callbacks[pButton->getCallbackID()]);
		}
	}
}