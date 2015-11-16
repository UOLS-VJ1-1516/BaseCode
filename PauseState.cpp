#pragma once
#include "PauseState.h"
#include "game.h"
#include "MenuState.h"
#include "MenuButton.h"

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

	GameObject* button = new MenuButton(new LoaderParams(200, 100, 251, 62, "resume", 3), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 315, 251, 62, "mainmenu", 3), s_menuToMain);
	m_gameObjects.push_back(button);
	m_gameObjects.push_back(button2);
	
	return true;
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	return true;
}

const std::string PauseState::s_menuID = "PAUSE";

std::string PauseState::getStateID() const {

	return PauseState::s_menuID;
}

void PauseState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->popState();
}

void PauseState::s_menuToMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}
