#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void MenuState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool MenuState::onEnter()
{
	GameObject *btn = new MenuButton(s_menuToPlay);
	btn->load(new LoaderParams(180, 65, "play", 0, 1, 0, *(new Vector2D(150, 250)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(btn);
	TextureManager::Instance()->load("jugar.bmp", "play", Game::Instance()->getRenderer());

	GameObject *btn2 = new MenuButton(s_exitFromMenu);
	btn2->load(new LoaderParams(135, 65, "exit", 0, 1, 0, *(new Vector2D(380, 250)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

	m_gameObjects.push_back(btn2);
	TextureManager::Instance()->load("exit.bmp", "exit", Game::Instance()->getRenderer());

	return true;

}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");
	return true;
}

void MenuState::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	Game::Instance()->clean();
}

std::string MenuState::getStateID() const {
	return s_menuID;
}