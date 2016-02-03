#include "PlayState.h"
#include "PauseState.h"
#include "StateParser.h"
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


	// parse the state
	StateParser stateParser;
	stateParser.parseState("./images/Tiny.xml", s_playID, &m_gObjects,
		&m_textureIDList);
	std::cout << "entering PlayState\n";

	
	return true;

	/*
	//-----Cargo la pantalla!
	if (!TextureManager::Instance()->load("./images/bird.png", "bird1", Game::Instance()->GetRenderer())) { return false; }
	if (!TextureManager::Instance()->load("./images/badbird.png", "badbird", Game::Instance()->GetRenderer())) { return false; }
	if (!TextureManager::Instance()->load("./images/coin.png", "coin1", Game::Instance()->GetRenderer())) { return false; }
	if (!TextureManager::Instance()->load("./images/nubes2.png", "fons", Game::Instance()->GetRenderer())) { return false; }

	GameObject* player1 = new Player();
	player1->load(new LoadPar(200, 400, 200, 180, "bird1", 1, 7, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));
	
	

	GameObject* enemy1 = new Player();
	enemy1->load(new LoadPar(230, 160, 200, 220, "badbird", 3, 6, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	GameObject* enemy2 = new Enemy();
	enemy2->load(new LoadPar(100, 100, 200, 180, "badbird", 1, 7, 2, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	GameObject* enemy3 = new Enemy();
	enemy3->load(new LoadPar(1200, 800, 200, 180, "badbird", 1, 7, 2, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	GameObject* enemy4 = new Enemy();
	enemy4->load(new LoadPar(1500, 500, 200, 180, "badbird", 1, 7, 2, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	GameObject* coin1 = new Enemy();
	coin1->load(new LoadPar(500, 300, 200, 200, "coin1", 1, 5, 2, Game::Instance()->getAncho(), Game::Instance()->getAlto()));


	GameObject* fons = new Fons();
	fons->load(new LoadPar(0, 400, 1600, 850, "fons", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	GameObject* fons2 = new Fons();
	fons2->load(new LoadPar(1600, 400, 1600, 850, "fons", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));


	m_gObjects.push_back(player1);
	m_gObjects.push_back(enemy1);
	m_gObjects.push_back(enemy2);
	m_gObjects.push_back(enemy3);
	m_gObjects.push_back(enemy4);
	m_gObjects.push_back(coin1);
	m_gObjects.push_back(fons);
	m_gObjects.push_back(fons2);
	
	return true;*/
}


bool PlayState::onExit() {
	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->
			clearFromTextureMap(m_textureIDList[i]);
	}

	m_textureIDList.clear();
	/*
	m_gObjects.clear();*/
	return true;
}

std::string PlayState::getStateID() const {
	return PlayState::s_playID;
};

