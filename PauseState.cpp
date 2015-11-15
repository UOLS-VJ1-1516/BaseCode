#include "PauseState.h"
#include "MenuState.h"

//ID del estado pause
const std::string PauseState::s_pauseID = "PAUSE";

//Callback para cuando se pulsa volver al estado de menu
void PauseState::s_pauseToMain()
{
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

//Callback para cuando se pulsa continuar jugando
void PauseState::s_resumePlay()
{
	Game::Instance()->getGameStateMachine()->popState();
}

//Función para que se hagan los updates de los game objects
void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

//Función para que se hagan los draw de los game objects
void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

//Función para cuando se entra al estado de pause donde se carga y se crean los game objects de este estado
bool PauseState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/resumeButton.bmp","resumebutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/mainMenuButton.bmp","mainbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(600, 250,	300, 100, "mainbutton", "assets/mainMenuButton.bmp",0,0, SDL_FLIP_NONE), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(600, 450,	300, 100, "resumebutton", "assets/resumeButton.bmp", 0, 0, SDL_FLIP_NONE), s_resumePlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	return true;
}

//Función para cuando se sale del estado pause que se limpian los gameobjects creados en este estado como las texturas
bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("resumebutton");
	TextureManager::Instance()->clearFromTextureMap("mainbutton");
	return true;
}