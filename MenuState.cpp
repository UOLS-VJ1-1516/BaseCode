#include "MenuState.h"
#include "Game.h"
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
	//GameObject* player1 = new Player();
	
	//player1->load(new LoadPar(200, 400, 200, 180, "bird1", 1, 7, 1, ancho, alto));
	GameObject *menuButton = new MenuButton(new LoadPar(150, 150, 300, 100, "playbtn.png",1,3,1, Game::Instance()->GetAncho(),Game::Instance()->GetAlto()), s_menuTOplay);
	if (menuButton == NULL) {
		return false;
	}
	
	
	/*
	GameObject* menuButton2 = new MenuButton(new LoadPar(150, 300, 400, 100, "playbtn.png", 1, 1, 1, Game::Instance()->GetAncho(), Game::Instance()->GetAlto()), s_exitMenu);
	if (menuButton2 == NULL) {
		return false;
	}*/
	m_gameObjects.push_back(menuButton);
	//m_gameObjects.push_back(menuButton2);
	TextureManager::Instance()->load("playbtn.png", "playbtn.png", Game::Instance()->GetRenderer());
	//TextureManager::Instance()->load("playbtn2.png", "playbtn2.png", Game::Instance()->GetRenderer());

	std::cout << "Entrada al menuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();



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