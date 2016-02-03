#include "MenuState.h"
#include "Game.h"
#include "StateParser.h"
#include "MenuButton.h"
#include <iostream>
#include "texturemanager.h"


const std::string MenuState::s_menuID = "MENU";


void MenuState::update()
{
	
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		
		m_gameObjects[i]->draw(Game::Instance()->GetRenderer());
	}
}

bool MenuState::onEnter()
{


	
	StateParser stateParser;
	stateParser.parseState("./images/miXML.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	
	m_callbacks.push_back(0);//pushback 0 callbackID start from 1
	m_callbacks.push_back(s_menuTOplay);
	m_callbacks.push_back(s_exitMenu);
	printf("\n\nHI2\n");
	setCallbacks(m_callbacks);
	printf("\n\nHI3\n");
	/*
	

	TextureManager::Instance()->load("./images/playbtn.png", "playbtn", Game::Instance()->GetRenderer());
	GameObject* playbutton = new MenuButton(new LoadPar((Game::Instance()->getAncho() / 2) - 300, (Game::Instance()->getAlto() / 2) - 100, 500, 100, "playbtn", 1, 3, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()),s_menuTOplay);

	//----Posicion de la imagen x, pos imagen y, tamaño imagen ancho, tamaño imagen alto, idtextura, numerofila,numero sprites,flip,render -----
	//player1->load(new LoadPar((Game::Instance()->getAncho()/2)-200, (Game::Instance()->getAlto()/2)-100, 500, 100, "playbtn", 1, 3, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()));
	
	m_gameObjects.push_back(playbutton);
	

	TextureManager::Instance()->load("./images/exit.png", "exit", Game::Instance()->GetRenderer());
	GameObject* exitbutton = new MenuButton(new LoadPar((Game::Instance()->getAncho() / 2) - 190, (Game::Instance()->getAlto() / 2+50), 295, 105, "exit", 1, 3, 1, Game::Instance()->getAncho(), Game::Instance()->getAlto()), s_exitMenu);
	m_gameObjects.push_back(exitbutton);

	*/
	return true;
}

bool MenuState::onExit(){
// clear the texture manager
for (int i = 0; i < m_textureIDList.size(); i++)
{
	TextureManager::Instance()->
		clearFromTextureMap(m_textureIDList[i]);
}


/*
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();


	*/
	std::cout << "Salida del MenuState\n";
	return true;
}



void MenuState::s_menuTOplay() {

	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitMenu() {




	Game::Instance()->getGameStateMachine()->popState();


	Game::Instance()->quit();

}


std::string MenuState::getStateID() const {

	return MenuState::s_menuID;
};


void MenuState::setCallbacks(const std::vector<Callback>&callbacks)
{
	// go through the game objects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback
		//based on the id passed in from the file
			if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
			{
				MenuButton* pButton =dynamic_cast<MenuButton*>(m_gameObjects[i]);
				pButton->setCallback(callbacks[pButton->getCallbackID()]);
			}
	}
}