#include "PauseState.h"
#include "game.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "StateParser.h"

const std::string PauseState::s_pauseID = "PAUSE";

PauseState::PauseState(){
}

PauseState::~PauseState(){
}


void PauseState::update() {
	for (int i = 0; i < m_gameObjectsPauseState.size(); i++)
	{
		m_gameObjectsPauseState[i]->update();
	}
}
void PauseState::render() {
	for (int i = 0; i < m_gameObjectsPauseState.size(); i++)
	{
		m_gameObjectsPauseState[i]->draw();
	}
}
bool PauseState::onEnter() {
	/*
	if (!TextureManager::Instance()->load("Resume-button.png", "resumebutton", Game::Instance()->getRender()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("Main-button.png", "mainbutton", Game::Instance()->getRender()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(160, 250, 322, 150, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(160, 100, 322, 150, "resumebutton"), s_resumePlay);
	
	*/
	StateParser stateParser;
	stateParser.parseState("assets/images.xml", s_pauseID, &m_gameObjectsPauseState,&m_textureIDList);
	m_callbacksPause.push_back(0);
	m_callbacksPause.push_back(s_pauseToMain);
	m_callbacksPause.push_back(s_resumePlay);
	setCallbacks(m_callbacksPause);
	
	return true;
}
bool PauseState::onExit() {
	/*
	for (int i = 0; i < m_gameObjectsPauseState.size(); i++)
	{
		m_gameObjectsPauseState[i]->clean();
	}
	m_gameObjectsPauseState.clear();
	TextureManager::Instance()->clearFromTextureMap("mainbutton");
	TextureManager::Instance()->clearFromTextureMap("resumebutton");
	*/
	// reset the mouse button states to false
	InputHandler::Instance()->reset();
	

	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	
	return true;
}
void PauseState::s_pauseToMain() {
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
void PauseState::s_resumePlay() {
	Game::Instance()->getStateMachine()->popState();
}

void PauseState::setCallbacks(const std::vector<Callback>&callbacks) {
	// go through the game objects
	for (int i = 0; i < m_gameObjectsPauseState.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
		if (dynamic_cast<MenuButton*>(m_gameObjectsPauseState[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjectsPauseState[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}
