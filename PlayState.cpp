#pragma once
#include "PlayState.h"
#include "game.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "StateParser.h"
#include "MenuButton.h"
#include "LevelParser.h"
#include "Level.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->getGameStateMachine()->pushState(new PauseState);
	}

	pLevel->update();

}

void PlayState::render() {

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}

	pLevel->render();
}

bool PlayState::onEnter() {

	// Parse the state
	StateParser stateParser;
	stateParser.parseState("XMLFile.xml", s_playID, &m_gameObjects, &m_textureIDList);

	LevelParser levelParser;
	pLevel = levelParser.parseLevel("map2.tmx");

	return true;
}

bool PlayState::onExit() {

	for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
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

std::string PlayState::getStateID() const {
	return s_playID;
}