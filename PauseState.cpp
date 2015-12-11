#include "PauseState.h"
#include "game.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "StateParser.h"

PauseState::PauseState() {}

void PauseState::update() {
	SDL_SetRenderDrawColor(Game::getInstance()->getRenderer(), 112, 112, 112, 255);
}

void PauseState::render() {
	for each (GameObject * go in gameObjects)
		go->draw();
}

void PauseState::handleEvents(SDL_Event e) {
	for each (GameObject * go in gameObjects)
		go->handleEvents(e);

	//EXIT
	if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
		resumeGame();
	}
}

bool PauseState::onEnter() {
	//OBJECTS
	StateParser::parseState("assets/xml/states_ini.xml", PauseState::getStateID(), &gameObjects, &textures);
	callbacks.push_back(NULL);
	callbacks.push_back(resumeGame);
	callbacks.push_back(exitToMenu);
	for each (GameObject * go in gameObjects) {
		if (dynamic_cast<MenuButton*>(go) && ((MenuButton*)go)->getCallbackID() != 0)
			((MenuButton*)go)->setCallback(callbacks[((MenuButton*)go)->getCallbackID()]);
	}
	return true;
}

bool PauseState::onExit() {
	for each(GameObject * go in gameObjects)
		go->clean();
	for each(auto texture in textures)
		TextureManager::getInstance()->remove(texture);
	gameObjects.clear();
	textures.clear();
	return true;
}

std::string PauseState::getStateID() const {
	return stateID;
}

void PauseState::resumeGame() {
	Game::getInstance()->getGameStateMachine()->popState();
}

void PauseState::exitToMenu() {
	Game::getInstance()->getGameStateMachine()->changeState(new MenuState());
}
