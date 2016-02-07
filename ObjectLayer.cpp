#include "ObjectLayer.h"
#include "Game.h"
#include "PlayState.h"
#include "MenuState.h"
void ObjectLayer::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (checkCollision(dynamic_cast<GameObject*>	(m_gameObjects[0]), dynamic_cast<GameObject*>(m_gameObjects[2])) || checkHueco((m_gameObjects[0])))
	{
 		Game::Instance()->getStateMachine()->pushState(new PlayState());
	}

	if (checkEnd(dynamic_cast<GameObject*>	(m_gameObjects[0]))) {
		Game::Instance()->getStateMachine()->pushState(new MenuState());
	}
}
void ObjectLayer::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}


bool ObjectLayer::checkCollision(GameObject* p1, GameObject* p2)
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

bool ObjectLayer::checkHueco(GameObject* p1)
{
	
	int bottomA;
	bottomA = p1->getPosition().getY() + p1->getHeight();
	//If any of the sides from A are outside of B
	if (bottomA >= Game::Instance()->getHeightWindow() - 20) { return true; }


	return false;
}

bool ObjectLayer::checkEnd(GameObject* p1)
{

	int rightA;
	rightA = p1->getPosition().getX() + p1->getWidth();
	//If any of the sides from A are outside of B
	if (rightA >= Game::Instance()->getwidthWindow()  - 10) { return true; }


	return false;
}