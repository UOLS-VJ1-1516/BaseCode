#include "MenuState.h"
//#include <string>
#include "MenuButton.h"
#include "TextureManager.h"
#include "game.h"
#include "PlayState.h"
#include "StateParser.h"
#include "SoundManager.h"

typedef void(*Callback)();
const std::string MenuState::s_menuID = "MENU";

MenuState::MenuState() {
}

MenuState::~MenuState() {
}

void MenuState::update()
{
	for (int i = 0; i < m_gameObjectsMenuState.size(); i++)
	{
		m_gameObjectsMenuState[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjectsMenuState.size(); i++)
	{
		m_gameObjectsMenuState[i]->draw();
	}
}

bool MenuState::onEnter()
{
	SoundManager::Instance()->playMusic("SongMenu", -1);
	SDL_Renderer* render;
	render = Game::Instance()->getRender();
	SDL_SetRenderDrawColor(render, 255, 229, 204, 255);
	Game::Instance()->setRender(render);
	// parse the state
	StateParser stateParser;
	stateParser.parseState("assets/images.xml", s_menuID, &m_gameObjectsMenuState, &m_textureIDList);
	m_callbacksMenu.push_back(0); //pushback 0 callbackID start from 1
	m_callbacksMenu.push_back(s_menuToPlay);
	m_callbacksMenu.push_back(s_exitFromMenu);
	// set the callbacks for menu items
	setCallbacks(m_callbacksMenu);

	return true;
}

bool MenuState::onExit()
{
	SoundManager::Instance()->stopMusic();
	for (int i = 0; i < m_gameObjectsMenuState.size(); i++) {
		m_gameObjectsMenuState[i]->clean();
	}
	m_gameObjectsMenuState.clear();
	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
			TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	// reset the mouse button states to false
	InputHandler::Instance()->reset();
	m_textureIDList.clear();
	return true;
}

void MenuState::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	Game::Instance()->running = false;
	Game::Instance()->clean();
}

void MenuState::setCallbacks(const std::vector<Callback>&callbacks){
	// go through the game objects
	for (int i = 0; i < m_gameObjectsMenuState.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
			if (dynamic_cast<MenuButton*>(m_gameObjectsMenuState[i]))
			{
				MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjectsMenuState[i]);
				pButton->setCallback(callbacks[pButton->getCallbackID()]);
			}
	}
}