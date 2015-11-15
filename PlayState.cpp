#pragma once
#include "PlayState.h"
#include "game.h"
#include "GameObject.h"
#include "InputHandler.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->clean();
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		p1->update();
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		p1->update();
	}

	InputHandler::Instance()->clean();
}

void PlayState::render() {

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {

	p1 = new Player();
	p2 = new Enemy();
	p3 = new Enemy();

	TextureManager::Instance()->load("walker.bmp", "walker", Game::Instance()->getRender());
	TextureManager::Instance()->load("kirby.bmp", "kirby", Game::Instance()->getRender());
	TextureManager::Instance()->load("tanooki.bmp", "tanooki", Game::Instance()->getRender());

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

	m_gameObjects.clear();
	return true;
}

std::string PlayState::getStateID() const {
	return s_playID;
}