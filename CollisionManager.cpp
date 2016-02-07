#pragma once
#include "CollisionManager.h"
#include <vector>
#include "SDL.h"



void CollisionManager::checkPlayerObjectsCollision(Player* pPlayer, const std::vector<GameObject*>* g_objects)
{
	// iterate through collision layers

	for (std::vector<GameObject*>::const_iterator it = g_objects->begin(); it != g_objects->end(); ++it)
	{
		GameObject* pGameObject = (*it);
		if (pGameObject->m_textureID == "player") {
			continue;
		}
		SDL_Rect player;
		player.x = pPlayer->m_position.getX();
		player.y = pPlayer->m_position.getY();
		player.w = pPlayer->m_width-50;
		player.h = pPlayer->m_height;
		SDL_Rect enemy;
		//printf("ID %s \n",pGameObject->m_textureID.c_str());
		enemy.x = pGameObject->m_position.getX();
		enemy.y = pGameObject->m_position.getY();
		enemy.w = pGameObject->m_width-50;
		enemy.h = pGameObject->m_height;
		if (isCollision(player, enemy)) {
			pPlayer->setPlayerState(true);
		}
	}
}
bool CollisionManager::isCollision(SDL_Rect a, SDL_Rect b) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
	{
		//printf("Top collision \n");
		return false;
	}

	if (topA >= bottomB)
	{
		//printf("Botom collision \n");
		return false;
	}
	if (rightA <= leftB)
	{
		//printf("Right collision \n");
		return false;
	}
	if (leftA >= rightB)
	{
		//printf("Left collision \n");
		return false;
	}

	return true;
}