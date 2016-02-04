#include "PauseState.h"
#include "StateParser.h"
#include "Game.h"

const std::string PauseState::s_pauseID = "PAUSE";
void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw(Game::Instance()->GetRenderer());
		
	}
}

bool PauseState::onEnter() {

	int x;

	StateParser stateParser;
	stateParser.parseState("./images/miXML.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuTOPlay);
	m_callbacks.push_back(s_menuTOMain);
	setCallbacks(m_callbacks);
	return true;
	


/*	TextureManager::Instance()->load("./images/pause2.png", "pausee", Game::Instance()->GetRenderer());
	GameObject* pausee = new MenuButton(new LoadPar(580,80, 500, 100, "pausee", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()), s_menuTOPlay);
	m_gameObjects.push_back(pausee);
	

	TextureManager::Instance()->load("./images/continue.png", "continue", Game::Instance()->GetRenderer());
	GameObject* playbutton = new MenuButton(new LoadPar((Game::Instance()->getAncho() / 2) - 275, (Game::Instance()->getAlto() / 2)-50, 500, 100, "continue", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()), s_menuTOPlay);
	
	//----- Posicion de la imagen x, pos imagen y, tamaño imagen ancho, tamaño imagen alto, idtextura, numerofila,numero sprites,flip,render -----
	//player1->load(new LoadPar((Game::Instance()->getAncho()/2)-200, (Game::Instance()->getAlto()/2)-100, 500, 100, "playbtn", 1, 3, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));

	m_gameObjects.push_back(playbutton);

	
	TextureManager::Instance()->load("./images/exit2.png", "exit2", Game::Instance()->GetRenderer());
	GameObject* exitbutton = new MenuButton(new LoadPar((Game::Instance()->getAncho() / 2) - 150, (Game::Instance()->getAlto() / 2 + 200), 295, 105, "exit2", 1, 1, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()), s_menuTOMain);
	m_gameObjects.push_back(exitbutton);  return true;*/
	;


}
bool PauseState::onExit() {
	

	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->
			clearFromTextureMap(m_textureIDList[i]);
	}
	m_gameObjects.clear();

	return true;
}


std::string PauseState::getStateID() const {

	return PauseState::s_pauseID;
};


void PauseState::s_menuTOMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::s_menuTOPlay() {
	Game::Instance()->getGameStateMachine()->popState();

}

void PauseState::setCallbacks(const std::vector<Callback>&callbacks)
{
	// go through the game objects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based
		//on the id passed in from the file
			if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
			{
				MenuButton* pButton =
					dynamic_cast<MenuButton*>(m_gameObjects[i]);
				pButton->setCallback(callbacks[pButton->getCallbackID()]);
			}
	}
}
