#include "PlayState.h"
#include "Player.h"
#include "NPC.h"
#include "game.h"
#include "PauseState.h"

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
	if (e.type == SDL_KEYUP && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
		Game::getInstance()->getGameStateMachine()->pushState(new PauseState());
	}
}

bool PlayState::onEnter() {
	//OBJECTS
	GameObject* player = new Player("player");
	player->load(new LoaderParams(
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w / 2),
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h / 2),
		128 / 4,
		48
	));
	((Player*)player)->setTexture("img_player", "assets/images/player_allmove.png", 4, 1);

	GameObject* npc1 = new NPC("princess");
	npc1->load(new LoaderParams(
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w / 2) - (128 / 4),
		((SDL_GetWindowSurface(Game::getInstance()->getWindow())->h / 3) * 2),
		128 / 4,
		196 / 4
	));
	((NPC*)npc1)->setTexture("img_princess", "assets/images/princess_allmove.png", 4, 4);

	GameObject* npc2 = new NPC("npc");
	npc2->load(new LoaderParams(
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w) - ((128 / 4) * 2),
		(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h / 3),
		128 / 4,
		196 / 4
	));
	((NPC*)npc2)->setTexture("img_npc", "assets/images/guy_allmove.png", 4, 4);

	gameObjects.push_back(player);
	gameObjects.push_back(npc1);
	gameObjects.push_back(npc2);
	//TEXTURES
	TextureManager* tManager = TextureManager::getInstance();
	tManager->load(((Player*)player)->getTexturePath(), ((Player*)player)->getTextureId(), Game::getInstance()->getRenderer());
	tManager->load(((NPC*)npc1)->getTexturePath(), ((NPC*)npc1)->getTextureId(), Game::getInstance()->getRenderer());
	tManager->load(((NPC*)npc2)->getTexturePath(), ((NPC*)npc2)->getTextureId(), Game::getInstance()->getRenderer());
	return true;
}

bool PlayState::onExit() {
	for each(GameObject * go in gameObjects) {
		go->clean();
		TextureManager::getInstance()->remove(go->getTextureId());
	}
	gameObjects.clear();
	return true;
}

std::string PlayState::getStateID() const {
	return std::string();
}

