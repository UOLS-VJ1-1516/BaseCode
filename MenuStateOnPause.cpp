#include "MenuStateOnPause.h"

const std::string MenuStateOnPause::s_menuID = "RESUME";



void MenuStateOnPause::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void MenuStateOnPause::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool MenuStateOnPause::onEnter()
{
	GameObject *btn = new MenuButton(s_menuToPlay);
	btn->load(new LoaderParams(135, 34, "resume", 0, 1, 0, *(new Vector2D(100, 300)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(btn);
	TextureManager::Instance()->load("boton_resume.bmp", "resume", Game::Instance()->getRenderer());

	GameObject *btn_menu = new MenuButton(s_exitFromMenu);
	btn_menu->load(new LoaderParams(135, 34, "mainmenu", 0, 1, 0, *(new Vector2D(300, 300)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(btn_menu);
	TextureManager::Instance()->load("main_menu.bmp", "mainmenu", Game::Instance()->getRenderer());

	return true;

}

bool MenuStateOnPause::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("resume");
	TextureManager::Instance()->clearFromTextureMap("mainmenu");
	return true;
}

void MenuStateOnPause::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->popState();
}

void MenuStateOnPause::s_exitFromMenu()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
std::string MenuStateOnPause::getStateID() const {
	return s_menuID;
}