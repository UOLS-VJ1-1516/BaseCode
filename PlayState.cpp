#include "PlayState.h"
#include "PauseState.h"

//ID del estado
const std::string PlayState::s_playID = "PLAY";

//Función para cargar al entrar en el estado de Play donde se cargan y se crean los diferentes gameobjects
bool PlayState::onEnter()
{

	if (!TextureManager::Instance()->load("gorda.bmp", "player", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("cine.bmp", "enemy", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("cine.bmp", "enemy1", Game::Instance()->getRenderer()))
	{
		return false;
	}

	player = new Player();
	player->load(new LoaderParams(100, 50, 92, 70, "player", "gorda.bmp", 8, 0));
	enemy1 = new Enemy();
	enemy1->load(new LoaderParams(500, 250, 41, 62, "enemy", "cine.bmp", 6, 0));
	enemy2 = new Enemy();
	enemy2->load(new LoaderParams(120, 400, 41, 62,"enemy1", "cine.bmp", 6, 0));
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(enemy2);
	return true;
}

//Función que realiza el update de los diferentes gameobjects
void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

//Función que printa los diferentes gameobjects constantemente
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

//Función para limpiar el estado de play al salir, los gameobjects y las texturas de estos
bool PlayState::onExit()
{

	for (size_t i = 0; i < m_gameObjects.size(); i++)
		 {
			m_gameObjects[i]->clean();
		}
	m_gameObjects.clear();

	return true;

}