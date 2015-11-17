#include "MenuState.h"
#include "PlayState.h"

//ID del estado menu
const std::string MenuState::s_menuID = "MENU";

//Función para cuando se crea el estado menu que crea los game objects de este estado
bool MenuState::onEnter()
{
	if (!TextureManager::Instance()->load("playbutton.bmp", "playerbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("exitbutton.bmp", "exitbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}

	button1 = new MenuButton(new LoaderParams(300, 150, 300, 100, "playbutton", "playbutton.bmp", 0, 0), s_menuToPlay);
	button2 = new MenuButton(new LoaderParams(300, 350, 300, 100, "exitbutton", "exitbutton.bmp", 0, 0), s_exitFromMenu);
	
	m_gameObjects.push_back(button1);
	
	m_gameObjects.push_back(button2);
	
	return true;
}

//Función para hacer el update de los game objects de este estado
void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

//Función para hacer el draw de los game objects de este estado
void MenuState::render()
{

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

//Función para cuando se sale del menu state que limpia los gameobjects y sus texturas
bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");
	return true;
}

//Callback para cambiar del estado del menu al estado del juego
void MenuState::s_menuToPlay()
{
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

//Callback para finalizar el juego que limpiar los diferentes estados
void MenuState::s_exitFromMenu()
{
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->deleteAllStates();
	Game::Instance()->exit();
}