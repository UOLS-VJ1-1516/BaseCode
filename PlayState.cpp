#include "PlayState.h"
#include "iostream"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	//copio lo que teniamos en game, ya que lo hemos sustituido por el play state
	player = new Player();
	player->load(new LoaderParams(200, 100, 200.48, 235, "player", 0, 6, 0));

	player2 = new Enemy();
	player2->load(new LoaderParams(200, 350, 200, 232, "player2", 0, 1, 0));

	player3 = new Enemy();
	player3->load(new LoaderParams(600, 300, 155, 208, "player3", 0, 5, 0));

	if (!TextureManager::Instance()->load("devilred.png", "player", Game::Instance()->getRender())) {
		return false;
	}

	if (!TextureManager::Instance()->load("daredevil.png", "player2", Game::Instance()->getRender())) {
		return false;
	}
	if (!TextureManager::Instance()->load("pixel_splatter.jpg", "player3", Game::Instance()->getRender())) {
		return false;
	}

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(player2);
	m_gameObjects.push_back(player3);

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	return true;
}