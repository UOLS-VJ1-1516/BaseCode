#include "PlayState.h"
#include "Game.h"
#include "texturemanager.h"

void PlayState::update() {
	player->update();
	enemy1->update();
	enemy2->update();
	nubes1->update();
	
	/*Player * player;
	Enemy * enemy1;
	Enemy * enemy2;
	Enemy * enemy3;
	Enemy * coin;
	Fons * nubes1;
	Fons * nubes2;*/

	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	InputHandler::Instance()->update();
	/*if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {

		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}*/

}
void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter() {
	player = new Player();
	enemy1 = new Enemy();
	enemy2 = new Enemy();
	nubes1 = new Fons();

	TextureManager::Instance()->load("bird.bmp", "player", Game::Instance()->GetRenderer());
	TextureManager::Instance()->load("badbird.bmp", "enemy1", Game::Instance()->GetRenderer());
	TextureManager::Instance()->load("badbird.bmp", "enemy2", Game::Instance()->GetRenderer());
	TextureManager::Instance()->load("nubes2.bmp", "nubes1", Game::Instance()->GetRenderer());
	//player1->load(new LoadPar(200, 400, 200, 180, "bird1", 1, 7, 1, ancho, alto));
	load = new LoadPar(100, 100, 35, 32, "player", 1,7,1,1000,600);
	load2 = new LoadPar(200, 200, 89, 78, "enemy1", 1,5,2, 1000, 600);
	load3 = new LoadPar(400, 300, 50, 70, "enemy2", 1,1, 1, 1000, 600);
	load4 = new LoadPar(400, 300, 50, 70, "nubes1", 1, 1, 1, 1000, 600);

	player->load(load);
	m_gameObjects.push_back(player);

	enemy1->load(load2);
	m_gameObjects.push_back(enemy1);

	enemy2->load(load3);
	m_gameObjects.push_back(enemy2);

	nubes1->load(load4);
	m_gameObjects.push_back(nubes1);



	return true;
}

const std::string PlayState::s_playID = "PLAY";
bool PlayState::onExit() {
	m_gameObjects.clear();
	return true;
}