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
		
		SDL_Rect player;
		player.x = pPlayer->m_position.getX();
		player.y = pPlayer->m_position.getY();
		player.w = pPlayer->m_width;
		player.h = pPlayer->m_height;
		SDL_Rect enemy;
		enemy.x = pGameObject->m_position.getX();
		enemy.y = pGameObject->m_position.getY();
		enemy.w = pGameObject->m_width;
		enemy.h = pGameObject->m_height;
		isCollision(player, enemy);
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
		printf("Top collision");
		return true;
	}

	if (topA >= bottomB)
	{
		printf("Botom collision");
		return true;
	}
	if (rightA <= leftB)
	{
		printf("Right collision");
		return true;
	}
	if (leftA >= rightB)
	{
		printf("Left collision");
		return true;
	}

	return false;
}