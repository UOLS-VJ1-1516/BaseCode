#include "PlayState.h"
#include <iostream>
#include "StateParser.h"


const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	TheInputHandler->update();
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		p1->incrementAccelerationX();
	}
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_LEFT))
	{
		p1->decrementAccelerationX();
	}

	if (TheInputHandler->Quit())
	{
		Game::Instance()->setIsRunning(false);
	}
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState);
	}
	
}
void PlayState::render()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	/*p1 = new Player();
	p2 = new StaticObject();
	p3 = new Enemy();
	lp = new LoaderParams(350, 100, 72.5, 91, "Player", 6, 0, 0, 35, 0.1);
	lp2 = new LoaderParams(10, 300, 64, 58, "pajarito", 4, 0, 0, 0, 0);
	lp3 = new LoaderParams(300, 200, 167, 90, "otro", 4, 4, 0, 4, 1);
	TheInputHandler = InputHandler::Instance();

	p1->load(lp);
	m_gameObjects.push_back(p1);

	p2->load(lp2);
	m_gameObjects.push_back(p2);

	p3->load(lp3);
	m_gameObjects.push_back(p3);

	TextureManager::Instance()->load("animation1.png", "Player", Game::Instance()->getRender());
	TextureManager::Instance()->load("bird1.png", "pajarito", Game::Instance()->getRender());
	TextureManager::Instance()->load("pantera1.png", "otro", Game::Instance()->getRender());
	
	std::cout << "entering PlayState\n";*/
	// Parse the state.

	StateParser::parseState("game.xml", s_playID, &m_gameObjects, &m_textureIDList);

	return true;
}
bool PlayState::onExit()
{
	m_gameObjects.clear();
	
	std::cout << "exiting PlayState\n";
	return true;
}