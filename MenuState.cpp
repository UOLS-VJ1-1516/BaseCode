#include "MenuState.h"
#include "game.h"
#include "MenuButton.h"
#include "PlayState.h"

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
	GameObject* playButton = new MenuButton();
	playButton->load(new LoaderParams(
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w / 2),
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h / 2 + 50),
		130,
		150/3,
		menuToPlay
	)); 
	((MenuButton*)playButton)->setTexture("btn_play", "assets/buttons/btn_play_all.png", 1, 3);

	GameObject* exitButton = new MenuButton();
	exitButton->load(new LoaderParams(
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w / 2),
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h / 2 + 150),
		130,
		150/3,
		exitFromMenu
	));
	((MenuButton*)exitButton)->setTexture("btn_exit", "assets/buttons/btn_exit_all.png", 1, 3);


	gameObjects.push_back(playButton);
	gameObjects.push_back(exitButton);

	//TEXTURES
	TextureManager* tManager = TextureManager::getInstance();
	tManager->load(((MenuButton*)playButton)->getTexturePath(), ((MenuButton*)playButton)->getTextureId(), Game::getInstance()->getRenderer());
	tManager->load(((MenuButton*)exitButton)->getTexturePath(), ((MenuButton*)exitButton)->getTextureId(), Game::getInstance()->getRenderer());
	return true;
}

bool MenuState::onExit() {
	for each(GameObject * go in gameObjects) {
		go->clean();
		TextureManager::getInstance()->remove(go->getTextureId());
	}
	gameObjects.clear();
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
