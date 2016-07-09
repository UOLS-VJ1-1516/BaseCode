#include "PlayState.h"
#include "iostream"

const std::string PlayState::s_playID = "PLAY";



void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	
	if (checkCollision(dynamic_cast<GameObject*> (m_gameObjects[0]), dynamic_cast<GameObject*> (m_gameObjects[1])))
	{
		Game::Instance()->getStateMachine()->pushState(new GameOverState());
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
	Player* player;
	Enemy* player2;
	Enemy* player3;
	//copio lo que teniamos en game, ya que lo hemos sustituido por el play state
	player = new Player();
	player->load(new LoaderParams(200, 100, 200.48, 235, "player", 0, 5, 0));
	
	player2 = new Enemy();
	player2->load(new LoaderParams(200, 100, 200, 232, "player2", 0, 5, 0));
	
	player3 = new Enemy();
	player3->load(new LoaderParams(200, 100, 155, 208, "player3", 0, 5, 0));
	
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

	TextureManager::Instance()->clear("devilred.png");
	TextureManager::Instance()->clear("daredevil.png");
	TextureManager::Instance()->clear("pixel_splatter.png");
	std::cout << "exiting MenuState\n";

	return true;
}

bool PlayState::checkCollision(GameObject * p1, GameObject * p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();
	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();
	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}