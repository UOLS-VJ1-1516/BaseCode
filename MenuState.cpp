#pragma once
#include "MenuState.h"
#include "TextureManager.h"
#include "game.h"
#include "PlayState.h"

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

	GameObject* button;
	GameObject* button2;

	if (!TextureManager::Instance()->load("play.bmp", "play", Game::Instance()->getRender())) {
		return false;
	}
	if (!TextureManager::Instance()->load("exit.bmp", "exit", Game::Instance()->getRender())) {
		return false;
	}

	button = new MenuButton(new LoaderParams(200, 100, 251, 62, "play", "play.bmp", 3), s_menuToPlay);
	button2 = new MenuButton(new LoaderParams(200, 250, 251, 62, "exit", "exit.bmp", 3), s_exitFromMenu);
	m_gameObjects.push_back(button);
	m_gameObjects.push_back(button2);

	return true;
}

bool MenuState::onExit() {

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	return true;
}

void MenuState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->clean();
}