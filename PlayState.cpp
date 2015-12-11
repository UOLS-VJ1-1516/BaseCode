#include "PlayState.h"
#include "Player.h"
#include "NPC.h"
#include "game.h"
#include "PauseState.h"
#include "StateParser.h"

PlayState::PlayState() {}

void PlayState::update() {
	//OBJECTS
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
	}

	//BACKGROUND COLOR
	//RED
	if (red < MAX_COLOR_VALUE && green == 0 && blue == 0 || red < MAX_COLOR_VALUE && green == 0 && blue == MAX_COLOR_VALUE) {
		red++;
	}
	else {
		if (red > 0 && green == MAX_COLOR_VALUE && blue == 0) red--;
	}
	//GREEN
	if (red == MAX_COLOR_VALUE && green < MAX_COLOR_VALUE && blue == 0) {
		green++;
	}
	else {
		if (red == 0 && green > 0 && blue == MAX_COLOR_VALUE) green--;
	}
	//BLUE
	if (red == 0 && green == MAX_COLOR_VALUE && blue < MAX_COLOR_VALUE) {
		blue++;
	}
	else {
		if (red == MAX_COLOR_VALUE && green == 0 && blue > 0) blue--;
	}
	SDL_SetRenderDrawColor(Game::getInstance()->getRenderer(), red, green, blue, alpha);
}

void PlayState::render() {
	for each (GameObject * go in gameObjects)
		go->draw();
}

void PlayState::handleEvents(SDL_Event e) {
	for each (GameObject * go in gameObjects)
		go->handleEvents(e);
	
	//EXIT
	if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
		Game::getInstance()->getGameStateMachine()->pushState(new PauseState());
	}
}

bool PlayState::onEnter() {
	//OBJECTS
	StateParser::parseState("assets/xml/states_ini.xml", PlayState::getStateID(), &gameObjects, &textures);
	return true;
}

bool PlayState::onExit() {
	for each(GameObject * go in gameObjects)
		go->clean();
	for each(auto texture in textures)
		TextureManager::getInstance()->remove(texture);
	gameObjects.clear();
	textures.clear();
	return true;
}

std::string PlayState::getStateID() const {
	return this->stateID;
}

