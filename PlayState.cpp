#include "PlayState.h"
#include "Game.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "TextureManager.h"


void PlayState::update() {
	if (InputHandler::Instance()->isKeyDown(SDLK_ESCAPE)) Game::Instance()->getStateMachine()->pushState(new MenuStateOnPause());
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool PlayState::onEnter() {
	GameObject *Player23 = new Player2();
	Player23->load(new LoaderParams(300, 310, "dragon", 1, 8, 0, *(new Vector2D(0, 10)), *(new Vector2D(3, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(Player23);
	TextureManager::Instance()->load("dragon.bmp", "dragon", Game::Instance()->getRenderer());

	GameObject *Player24 = new Player2();
	Player24->load(new LoaderParams(125, 100, "vulture", 1, 6, 0, *(new Vector2D(50, 300)), *(new Vector2D(8, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(Player24);
	TextureManager::Instance()->load("vulture_sprites.bmp", "vulture", Game::Instance()->getRenderer());

	GameObject *player = new Player();
	player->load(new LoaderParams(116, 200, "player", 1, 6, 0, *(new Vector2D(300, 500)), *(new Vector2D(0, 0)), *(new Vector2D(18, 0)), *(new Vector2D(4, 0)), *(new Vector2D(4, 0))));

	m_gameObjects.push_back(player);
	TextureManager::Instance()->load("player1.bmp", "player", Game::Instance()->getRenderer());

	return true;
};


bool PlayState::onExit() {
	m_gameObjects.clear();
	return true;
};

const std::string PlayState::s_playID = "Play";

std::string PlayState::getStateID() const {
	return PlayState::s_playID;
};