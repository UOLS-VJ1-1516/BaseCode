#pragma once
#include "Player.h"
#include <vector>
#include "SDL.h"
class CollisionManager
{
public:
	CollisionManager() {};
	~CollisionManager() {};
	void checkPlayerObjectsCollision(Player* pPlayer, const std::vector<GameObject*>* objects);
	bool isCollision(SDL_Rect a, SDL_Rect b);

};
