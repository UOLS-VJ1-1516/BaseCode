#include "MenuState.h"
#include "game.h"
#include "MenuButton.h"
#include "PlayState.h"
#include <vector>
#include "StateParser.h"

MenuState::MenuState(){}

void MenuState::update() {
	SDL_SetRenderDrawColor(Game::getInstance()->getRenderer(), 42, 42, 42, 255);
}

void MenuState::render() {
	for each (GameObject * go in gameObjects)
		go->draw();
}

void MenuState::handleEvents(SDL_Event e) {
	for each (GameObject * go in gameObjects)
		go->handleEvents(e);

	//EXIT
	if (e.type == SDL_KEYUP && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
		Game::getInstance()->setRunning(false);
	}
}

bool MenuState::onEnter() {
	//OBJECTS
	StateParser::parseState("assets/xml/states_ini.xml", MenuState::getStateID(), &gameObjects, &textures);
	callbacks.push_back(NULL);
	callbacks.push_back(menuToPlay);
	callbacks.push_back(exitFromMenu);
	for each (GameObject * go in gameObjects) {
		if (dynamic_cast<MenuButton*>(go) && ((MenuButton*)go)->getCallbackID() != 0)
			((MenuButton*)go)->setCallback(callbacks[((MenuButton*)go)->getCallbackID()]);
	}
	return true;
}

bool MenuState::onExit() {
	for each(GameObject * go in gameObjects)
		go->clean();
	for each(std::string texture in textures)
		TextureManager::getInstance()->remove(texture);
	gameObjects.clear();
	textures.clear();
	return true;
}

std::string MenuState::getStateID() const {
	return stateID;
}

void MenuState::menuToPlay() {
	Game::getInstance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::exitFromMenu() {
	Game::getInstance()->setRunning(false);
}
