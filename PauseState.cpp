#include "PauseState.h"
#include "game.h"
#include "MenuButton.h"
#include "MenuState.h"

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
	if (e.type == SDL_KEYUP && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
		Game::getInstance()->setRunning(false);
	}
}

bool PauseState::onEnter() {
	//OBJECTS
	GameObject* resumeBtn = new MenuButton();
	resumeBtn->load(new LoaderParams(
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w / 2 - 160),
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h / 2 + 100),
		130,
		150 / 3,
		resumeGame
	));
	((MenuButton*)resumeBtn)->setTexture("btn_resume", "assets/buttons/btn_resume_all.png", 1, 3);

	GameObject* exitButton = new MenuButton();
	exitButton->load(new LoaderParams(
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w / 2 + 160),
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h / 2 + 100),
		130,
		150 / 3,
		exitToMenu
	));
	((MenuButton*)exitButton)->setTexture("btn_backToMenu", "assets/buttons/btn_exit_all.png", 1, 3);


	gameObjects.push_back(resumeBtn);
	gameObjects.push_back(exitButton);

	//TEXTURES
	TextureManager* tManager = TextureManager::getInstance();
	tManager->load(((MenuButton*)resumeBtn)->getTexturePath(), ((MenuButton*)resumeBtn)->getTextureId(), Game::getInstance()->getRenderer());
	tManager->load(((MenuButton*)exitButton)->getTexturePath(), ((MenuButton*)exitButton)->getTextureId(), Game::getInstance()->getRenderer());
	return true;
}

bool PauseState::onExit() {
	for each(GameObject * go in gameObjects) {
		go->clean();
		TextureManager::getInstance()->remove(go->getTextureId());
	}
	gameObjects.clear();
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
