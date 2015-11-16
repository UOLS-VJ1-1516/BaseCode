#pragma once
#include "PlayState.h"
#include "game.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "PauseState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	//InputHandler::Instance()->update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getGameStateMachine()->pushState(new PauseState);
	}

}

void PlayState::render() {

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {

	p1 = new Player();
	p2 = new Enemy();
	p3 = new Enemy();

	if (!TextureManager::Instance()->load("walker.bmp", "walker", Game::Instance()->getRender())) {
		return false;
	}
	if (!TextureManager::Instance()->load("kirby.bmp", "kirby", Game::Instance()->getRender())) {
		return false;
	}

	if (!TextureManager::Instance()->load("tanooki.bmp", "tanooki", Game::Instance()->getRender())) {
		return false;
	}

	LoaderParams* load1 = new LoaderParams(300, 200, 60, 38, "walker", 12);
	LoaderParams* load2 = new LoaderParams(50, 50, 30, 27, "kirby", 6);
	LoaderParams* load3 = new LoaderParams(550, 400, 37, 35, "tanooki", 4);

	p1->load(load1);
	p2->load(load2);
	p3->load(load3);

	m_gameObjects.push_back(p1);
	m_gameObjects.push_back(p2);
	m_gameObjects.push_back(p3);
	
	return true;
}

bool PlayState::onExit() {

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	return true;
}

std::string PlayState::getStateID() const {
	return s_playID;
}