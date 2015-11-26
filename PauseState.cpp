#include "PauseState.h"
#include "Game.h"


void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
		
	}
}

bool PauseState::onEnter() {
	TextureManager::Instance()->load("./images/pause2.png", "pausee", Game::Instance()->GetRenderer());
	GameObject* pausee = new MenuButton(new LoadPar(580,80, 500, 100, "pausee", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()), s_menuTOPlay);
	m_gameObjects.push_back(pausee);
	

	TextureManager::Instance()->load("./images/continue.png", "continue", Game::Instance()->GetRenderer());
	GameObject* playbutton = new MenuButton(new LoadPar((Game::Instance()->getAncho() / 2) - 275, (Game::Instance()->getAlto() / 2)-50, 500, 100, "continue", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()), s_menuTOPlay);
	
	//----- Posicion de la imagen x, pos imagen y, tamaño imagen ancho, tamaño imagen alto, idtextura, numerofila,numero sprites,flip,render -----
	//player1->load(new LoadPar((Game::Instance()->getAncho()/2)-200, (Game::Instance()->getAlto()/2)-100, 500, 100, "playbtn", 1, 3, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	m_gameObjects.push_back(playbutton);

	
	TextureManager::Instance()->load("./images/exit2.png", "exit2", Game::Instance()->GetRenderer());
	GameObject* exitbutton = new MenuButton(new LoadPar((Game::Instance()->getAncho() / 2) - 150, (Game::Instance()->getAlto() / 2 + 200), 295, 105, "exit2", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()), s_menuTOMain);
	m_gameObjects.push_back(exitbutton);
	return true;


}
bool PauseState::onExit() {
	m_gameObjects.clear();

	return true;
}

const std::string PauseState::s_pauseID = "PAUSE";

std::string PauseState::getStateID() const {
	return PauseState::s_pauseID;
}

void PauseState::s_menuTOMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::s_menuTOPlay() {
	Game::Instance()->getGameStateMachine()->popState();

}
