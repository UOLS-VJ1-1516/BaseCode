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
};

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		
		m_gameObjects[i]->draw(Game::Instance()->GetRenderer());
	}
};

bool MenuState::onEnter()
{

	
	StateParser stateParser;
	stateParser.parseState("./images/miXML.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	int i;

	
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuTOplay);
	m_callbacks.push_back(s_exitMenu);

	setCallbacks(m_callbacks);
	

	return true;
};

void MenuState::setCallbacks(const std::vector<Callback>&callbacks)
{
	int x = 0;
	int i = 0;
	// go through the game objects
	for (i = 0; i < m_gameObjects.size(); i++)
	{

		// if they are of type MenuButton then assign a callback
		//based on the id passed in from the file

		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {

			
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			x = pButton->getCallbackID();
			pButton->setCallback(callbacks[x]);
		}

	}
}




bool MenuState::onExit(){

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	m_textureIDList.clear();
	
	
	
	
	return true;
}



void MenuState::s_menuTOplay() {
	printf("ENTRO al playstate desde MenuState\n");
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
	
};

void MenuState::s_exitMenu() {




	Game::Instance()->getGameStateMachine()->popState();


	Game::Instance()->quit();

}


std::string MenuState::getStateID() const {

	return MenuState::s_menuID;
};

