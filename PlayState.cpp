#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	 

	for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->update();
	}
	//------Compruebo teclas y escapeeeeeeeee
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {

		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

}
void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->draw();
	}
}
bool PlayState::onEnter() {


	//-----Cargo la pantalla!
	if (!TextureManager::Instance()->load("./images/ninja.png", "ninja", Game::Instance()->GetRenderer())) { return false; }
	if (!TextureManager::Instance()->load("./images/Enemy_Knight.png", "Enemy_Knight", Game::Instance()->GetRenderer())) { return false; }
	if (!TextureManager::Instance()->load("./images/coin.png", "coin1", Game::Instance()->GetRenderer())) { return false; }
	if (!TextureManager::Instance()->load("./images/teclas.png", "teclas", Game::Instance()->GetRenderer())) { return false; }
	
	GameObject* player1 = new Player();
	player1->load(new LoadPar(200, Game::Instance()->getAlto() - 300, 200, 180, "ninja", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));
	//(float x, float y, int width, int height, const char* id, int currentRow, int sprits, int flip, int anchopantalla, int altopantalla
	

	GameObject* enemy1 = new Enemy();
	enemy1->load(new LoadPar(200, Game::Instance()->getAlto() - 300, 200, 180, "Enemy_Knight", 2, 4, 2, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	GameObject* coin1 = new Enemy();
	coin1->load(new LoadPar(500, 300, 200, 200, "coin1", 1, 5, 2, Game::Instance()->getAncho(), Game::Instance()->getAlto()));


	GameObject* teclas = new Fons();
	teclas->load(new LoadPar(Game::Instance()->getAncho()-500, Game::Instance()->getAlto()-150, 500, 230, "teclas", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	//GameObject* fons2 = new Fons();
	//fons2->load(new LoadPar(1600, 400, 1600, 850, "fons", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));


	m_gObjects.push_back(player1);
	m_gObjects.push_back(enemy1);
	m_gObjects.push_back(coin1);
	m_gObjects.push_back(teclas);
	//m_gObjects.push_back(fons2);

	return true;
}


bool PlayState::onExit() {
	m_gObjects.clear();
	return true;
}