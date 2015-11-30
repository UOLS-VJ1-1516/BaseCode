#include "MenuState.h"
#include "Game.h"
#include "StateParser.h"

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
};

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool MenuState::onEnter() {
	StateParser::parseState("menu.xml", getStateID(), &m_gameObjects, &idTextures);
	
	callbacks.push_back(NULL);
	callbacks.push_back(s_menuToPlay);
	callbacks.push_back(s_exitFromMenu);

	for each (MenuButton * btn in m_gameObjects)
	{
		if (btn->getcallbackID() != 0)
		{
			btn->setCallback(callbacks[btn->getcallbackID()]);
		}
	}

	return true;
};

bool MenuState::onExit() {
	m_gameObjects.clear();
	mb->clean();
	mb2->clean();
	so->clean();
	TextureManager::Instance()->clean("play.bmp");
	TextureManager::Instance()->clean("salir.bmp");
	return true;
};

const std::string MenuState::s_menuID = "Menu";

std::string MenuState::getStateID() const{

	return MenuState::s_menuID;
};

void MenuState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
};

void MenuState::s_exitFromMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->voidAllOldStates();
	Game::Instance()->setflag(false);
}; 

std::vector<int> MenuState::theMiddle(int width, int height) {
	m_position = std::vector<int>(2, 0);
	m_position[0] = (Game::Instance()->getScreenWidth() / 2) - width / 2;
	m_position[1] = (Game::Instance()->getScreenHeight() / 2) - height / 2;

	return m_position;
};
