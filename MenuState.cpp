#pragma once
#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void MenuState::render() {
	
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool MenuState::onEnter() {

	return true;
}
bool MenuState::onExit() {

	return true;
}